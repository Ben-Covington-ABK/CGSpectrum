// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANTRUM_DoorInteractionComponent_generated_h
#error "DoorInteractionComponent.generated.h already included, missing '#pragma once' in DoorInteractionComponent.h"
#endif
#define TANTRUM_DoorInteractionComponent_generated_h

#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_SPARSE_DATA
#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAlert);


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAlert);


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDoorInteractionComponent(); \
	friend struct Z_Construct_UClass_UDoorInteractionComponent_Statics; \
public: \
	DECLARE_CLASS(UDoorInteractionComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tantrum"), NO_API) \
	DECLARE_SERIALIZER(UDoorInteractionComponent)


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUDoorInteractionComponent(); \
	friend struct Z_Construct_UClass_UDoorInteractionComponent_Statics; \
public: \
	DECLARE_CLASS(UDoorInteractionComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tantrum"), NO_API) \
	DECLARE_SERIALIZER(UDoorInteractionComponent)


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDoorInteractionComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDoorInteractionComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDoorInteractionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDoorInteractionComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDoorInteractionComponent(UDoorInteractionComponent&&); \
	NO_API UDoorInteractionComponent(const UDoorInteractionComponent&); \
public:


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDoorInteractionComponent(UDoorInteractionComponent&&); \
	NO_API UDoorInteractionComponent(const UDoorInteractionComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDoorInteractionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDoorInteractionComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDoorInteractionComponent)


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__DesiredRotation() { return STRUCT_OFFSET(UDoorInteractionComponent, DesiredRotation); } \
	FORCEINLINE static uint32 __PPO__TimeToRotate() { return STRUCT_OFFSET(UDoorInteractionComponent, TimeToRotate); } \
	FORCEINLINE static uint32 __PPO__OpenCurve() { return STRUCT_OFFSET(UDoorInteractionComponent, OpenCurve); } \
	FORCEINLINE static uint32 __PPO__TriggerBox() { return STRUCT_OFFSET(UDoorInteractionComponent, TriggerBox); }


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_21_PROLOG
#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_PRIVATE_PROPERTY_OFFSET \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_SPARSE_DATA \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_RPC_WRAPPERS \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_INCLASS \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_PRIVATE_PROPERTY_OFFSET \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_SPARSE_DATA \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_INCLASS_NO_PURE_DECLS \
	Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANTRUM_API UClass* StaticClass<class UDoorInteractionComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Tantrum_Source_Tantrum_Public_DoorInteractionComponent_h


#define FOREACH_ENUM_STATE(op) \
	op(Closed) \
	op(Closing) \
	op(Open) \
	op(Opening) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
