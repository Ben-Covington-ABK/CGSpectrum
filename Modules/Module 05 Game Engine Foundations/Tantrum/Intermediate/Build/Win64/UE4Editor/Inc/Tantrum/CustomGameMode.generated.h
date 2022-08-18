// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TANTRUM_CustomGameMode_generated_h
#error "CustomGameMode.generated.h already included, missing '#pragma once' in CustomGameMode.h"
#endif
#define TANTRUM_CustomGameMode_generated_h

#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_SPARSE_DATA
#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_RPC_WRAPPERS
#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACustomGameMode(); \
	friend struct Z_Construct_UClass_ACustomGameMode_Statics; \
public: \
	DECLARE_CLASS(ACustomGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tantrum"), NO_API) \
	DECLARE_SERIALIZER(ACustomGameMode)


#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_INCLASS \
private: \
	static void StaticRegisterNativesACustomGameMode(); \
	friend struct Z_Construct_UClass_ACustomGameMode_Statics; \
public: \
	DECLARE_CLASS(ACustomGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Tantrum"), NO_API) \
	DECLARE_SERIALIZER(ACustomGameMode)


#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomGameMode(ACustomGameMode&&); \
	NO_API ACustomGameMode(const ACustomGameMode&); \
public:


#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomGameMode(ACustomGameMode&&); \
	NO_API ACustomGameMode(const ACustomGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomGameMode)


#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_PRIVATE_PROPERTY_OFFSET
#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_12_PROLOG
#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_SPARSE_DATA \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_RPC_WRAPPERS \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_INCLASS \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_SPARSE_DATA \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_INCLASS_NO_PURE_DECLS \
	Tantrum_Source_Tantrum_Public_CustomGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TANTRUM_API UClass* StaticClass<class ACustomGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Tantrum_Source_Tantrum_Public_CustomGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
