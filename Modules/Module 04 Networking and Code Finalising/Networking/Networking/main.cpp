#include <enet/enet.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <string>
#include <vector>

using namespace std;
typedef vector<ENetPeer*> ENetPeers;

string number;
int range = 1;
bool active = true;
ENetAddress address;
ENetHost* server;
ENetHost* client;
ENetPeer* peer;
ENetPeers peers;
ENetEvent event;
vector<string> StartModes { 
	"Create Server", 
	"Create Client", 
	"Exit"
};
vector<string> GameModes {
	"Guessing Game",
	"Chat Room",
	"Exit"
};

void EraseLine()
{
	cout << "\x1b[2K"	// Delete current line
		<< "\x1b[1A"	// Move cursor up one
		<< "\x1b[2K"	// Delete the entire line
		<< "\r";		// Resume the cursor at beginning of line
}
string EnterLine()
{
	string line;
	getline(cin, line);
	EraseLine();
	return line;
}
string NewNumber()
{
	return to_string(rand() % range + 1);
}
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
			cout << "A new client connected from "
				<< event.peer->address.host << " : "
				<< event.peer->address.port << ".\n";

			/* Store any relevant client information here. */
			event.peer->data = (void*)event.peer->address.port;
			peers.push_back(event.peer);
			break;
		case ENET_EVENT_TYPE_RECEIVE:
		{
			int len = (int)event.packet->dataLength;
			int id = (int)event.peer->data;
			string rawData = (char*)event.packet->data;
			int game = atoi(rawData.substr(0, 1).c_str());
			string data = rawData.substr(2);
			cout << "A packet of length " << len
				<< " was received from " << id 
				<< " containing " << rawData << ".\n";
				//<< " on channel " << event.channelID
			switch(game)
			{
			case 1: // Guessing Game
			{
				if(data == number)
				{
					Broadcast(server, data + " was the correct number!");
				}
				else
				{
					Broadcast(server, data + " is incorrect." + 
						" The number was " + number + ".");
				}
				number = NewNumber();
				break;
			}
			case 2: // Chat Room
			{
				Broadcast(server, to_string(id) + ": " + data);
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
				message = EnterLine();
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
				message = EnterLine();
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
			number = NewNumber();
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
