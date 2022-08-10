#include <enet/enet.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <string>
#include <vector>

using namespace std;
typedef vector<ENetPeer*> ENetPeers;

bool active = true;
ENetAddress address;
ENetHost* server;
ENetHost* client;
ENetPeer* peer;
ENetPeers peers;
ENetEvent event;
int number;

vector<string> StartModes
{ 
	"Create Server", 
	"Create Client", 
	"Exit"
};
vector<string> GameModes
{
	"Guessing Game",
	"Chat Room",
	"Exit"
};

int Select(vector<string> options)
{
	string input;
	for (int i = 0; i < options.size(); i++)
	{
		cout << i + 1 << ". " << options[i] << endl;
	}
	getline(cin, input);
	system("cls");
	return atoi(input.c_str());
}
void Broadcast(ENetHost* host, string message)
{
	/* Create a reliable packet of size 7 containing "packet\0" */
	ENetPacket* packet = enet_packet_create(message.c_str(),
		message.size() + 1,
		ENET_PACKET_FLAG_RELIABLE);

	enet_host_broadcast(host, 0, packet);
	//enet_peer_send(event.peer, 0, packet);

	/* One could just use enet_host_service() instead. */
	//enet_host_service();
	enet_host_flush(host);
}
void CreateServer()
{
	//cout << "1. Create Server" << endl;
	/* Bind the server to the default localhost.     */
	/* A specific host address can be specified by   */
	/* enet_address_set_host (& address, "x.x.x.x"); */
	address.host = ENET_HOST_ANY;
	/* Bind the server to port 1234. */
	address.port = 1234;
	server = enet_host_create(&address /* the address to bind the server host to */,
		32		/* allow up to 32 clients and/or outgoing connections */,
		2		/* allow up to 2 channels to be used, 0 and 1 */,
		0		/* assume any amount of incoming bandwidth */,
		0		/* assume any amount of outgoing bandwidth */);
	if (server == nullptr)
	{
		fprintf(stderr,	"An error occurred while trying to create an ENet server host.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "Created Server on Port: " << server->address.port << endl;
	}

}
void CreateClient()
{
	//cout << "2. Create Client" << endl;
	client = enet_host_create(NULL /* create a client host */,
		1		/* only allow 1 outgoing connection */,
		2		/* allow up 2 channels to be used, 0 and 1 */,
		0		/* assume any amount of incoming bandwidth */,
		0		/* assume any amount of outgoing bandwidth */);
	if (client == nullptr)
	{
		fprintf(stderr,	"An error occurred while trying to create an ENet client host.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "Created new Client." << endl;
	}
}
void ConnectToServer()
{
	/* Connect to some.server.net:1234. */
	enet_address_set_host(&address, "127.0.0.1");
	address.port = 1234;
	/* Initiate the connection, allocating the two channels 0 and 1. */
	peer = enet_host_connect(client, &address, 2, 0);
	if (peer == NULL)
	{
		fprintf(stderr,	"No available peers for initiating an ENet connection.\n");
		exit(EXIT_FAILURE);
	}

	//cout << "Attempting to connect on Port: " << peer->address.port << endl;

	/* Wait up to 5 seconds for the connection attempt to succeed. */
	if (enet_host_service(client, &event, 5000) > 0 &&
		event.type == ENET_EVENT_TYPE_CONNECT)
	{
		//puts("Connection to some.server.net:1234 succeeded.");
		cout << "Connection to Server "
			<< event.peer->address.port
			<< " succeeded.\n";
	}
	else
	{
		/* Either the 5 seconds are up or a disconnect event was */
		/* received. Reset the peer in the event the 5 seconds   */
		/* had run out without any significant event.            */
		enet_peer_reset(peer);
		//puts("Connection to some.server.net:1234 failed.");
		cout << "Connection to Server "
			<< event.peer->address.port
			<< " failed.\n";
	}
}
void PollServer()
{
	/* Wait up to 1000 milliseconds for an event. */
	while (enet_host_service(server, &event, 1000) > 0 || true)
	{
		//string data; 
		switch (event.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			/*
			printf("A new client connected from %x:%u.\n",
				event.peer->address.host,
				event.peer->address.port);
			*/
			cout << "A new client connected from "
				<< event.peer->address.host << " : "
				<< event.peer->address.port << ".\n";

			peers.push_back(event.peer);

			/* Store any relevant client information here. */
			//event.peer->data = (void*)"Client information";
			event.peer->data = (void*)event.peer->address.port;
			
			break;
		case ENET_EVENT_TYPE_RECEIVE:
		{
			//data = string((char*)event.packet->data, event.packet->dataLength);
			/*
			printf("A packet of length %u containing %s was received from %s on channel %u.\n",
				event.packet->dataLength,
				event.packet->data,
				event.peer->data,
				event.channelID);
			*/
			cout << "A packet of length " << event.packet->dataLength
				<< " containing " << event.packet->data
				<< " was received from " << (int)event.peer->data
				<< " on channel " << event.channelID << ".\n";
			
			string rawData = (char*)event.packet->data;
			int game = atoi(rawData.substr(0, 1).c_str());
			string data = rawData.substr(2);

			cout << endl << game << "|" << data << endl;

			switch(game)
			{
			case 1:
			{
				int guess = atoi(data.c_str());
				if(guess == number)
				{
					Broadcast(server, "Correct! number was " + to_string(number));
				}
				else
				{
					Broadcast(server, "Incorrect! number was " + to_string(number));
				}
				number = rand() % 100 + 1;
				break;
			}
			case 2:
			{
				Broadcast(server, to_string((int)event.peer->data) + ": " + data);
				break;
			}
			default:
			{
				break;
			}
			}


			/* Clean up the packet now that we're done using it. */
			enet_packet_destroy(event.packet);
			break;
		}

		case ENET_EVENT_TYPE_DISCONNECT:
			printf("%s disconnected.\n", event.peer->data);
			/* Reset the peer's client information. */
			event.peer->data = NULL;
		}
	}
}
void PollClient() 
{
	//ENetEvent event;
	/* Wait up to 1000 milliseconds for an event. */
	while (enet_host_service(client, &event, 1000) > 0 || true)
	{
		switch (event.type)
		{
		case ENET_EVENT_TYPE_RECEIVE:
			cout << (char*)event.packet->data << endl;
			/* Clean up the packet now that we're done using it. */
			enet_packet_destroy(event.packet);
		}
	}
}
void UpdateServer() 
{
	while(true)
	{
		//Broadcast();
		//cout << "still alive" << endl;
	}
}
void UpdateClient() 
{
	int selection = Select(GameModes);
	bool gameActive = true;
	while (gameActive)
	{
		switch (selection)
		{
		case 1:
		{
			system("cls");
			cout << "Welcome to the guessing game!\n"
				<< "Enter a guess of what the number is.\n";
			string message;
			while(true)
			{
				getline(cin, message);
				message = "1|" + message;
				Broadcast(client, message);
			}
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Welcome to the chat room!\n"
				<< "Enter a message to share.\n";
			string message;
			while (true)
			{
				getline(cin, message);
				message = "2|" + message;
				Broadcast(client, message);
			}
			break;
		}
		case 3:
		default:
		{
			gameActive = false;
			break;
		}
		}
	}
}

int main(int argc, char** argv)
{
	// This program will create different sequenceof
	// random numbers on every program run
	// Use current time as seed for random generator
	srand(time(0));
	if (enet_initialize() != 0)
	{
		const char* error = "An error occured while initilizing ENet.\n";
		fprintf(stderr, error);
		cout << error;
		return EXIT_FAILURE;
	}
	atexit(enet_deinitialize);
	while (active)
	{
		switch(Select(StartModes))
		{
		case 1: // Server
		{
			CreateServer();
			number = rand() % 100 + 1;
			thread serverPoller { PollServer };
			UpdateServer();
			enet_host_destroy(server);
			break;
		}
		case 2: // Client
		{
			CreateClient();
			ConnectToServer();
			thread clientPoller { PollClient };
			UpdateClient();
			enet_host_destroy(client);
			break;
		}
		case 3: // Exit
		default: 
		{
			active = false;
			break;
		}
		}
	}
	return EXIT_SUCCESS;
}
