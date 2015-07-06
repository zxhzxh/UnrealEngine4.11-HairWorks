// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MovieSceneBinding.generated.h"


class UMovieSceneTrack;


/**
 * A set of tracks bound to runtime objects
 */
USTRUCT()
struct FMovieSceneObjectBinding
{
	GENERATED_USTRUCT_BODY()

	/** Default constructor. */
	FMovieSceneObjectBinding() { }

	/**
	 * Creates and initializes a new instance.
	 *
	 * @param InObjectGuid
	 * @param InBindingName
	 * @param InTracks
	 */
	FMovieSceneObjectBinding(const FGuid& InObjectGuid, const FString& InBindingName, const TArray<UMovieSceneTrack*>& InTracks)
		: ObjectGuid(InObjectGuid)
		, BindingName(InBindingName)
		, Tracks(InTracks)
	{ }

	/**
	 * Creates and initializes a new instance.
	 *
	 * @param InObjectGuid
	 * @param InBindingName
	 */
	FMovieSceneObjectBinding(const FGuid& InObjectGuid, const FString& InBindingName)
		: ObjectGuid(InObjectGuid)
		, BindingName(InBindingName)
	{ }

	/**
	 * @return The time range of all tracks in this binding
	 */
	TRange<float> GetTimeRange() const;

	/**
	 * @return The guid of runtime objects in this binding
	 */
	const FGuid& GetObjectGuid() const
	{
		return ObjectGuid;
	}

	/**
	 * @return The display name of the binding
	 */
	const FString& GetName() const
	{
		return BindingName;
	} 

	/**
	 * Adds a new track to this binding
	 *
	 * @param NewTrack	The track to add
	 */
	void AddTrack(UMovieSceneTrack& NewTrack);

	/**
	 * Removes a track from this binding
	 * 
	 * @param Track	The track to remove
	 * @return true if the track was successfully removed, false if the track could not be found
	 */
	bool RemoveTrack(UMovieSceneTrack& Track);

	/**
	 * @return All tracks in this binding
	 */
	const TArray<UMovieSceneTrack*>& GetTracks() const
	{
		return Tracks;
	}

private:

	/** Object binding guid for runtime objects */
	UPROPERTY()
	FGuid ObjectGuid;
	
	/** Display name */
	UPROPERTY()
	FString BindingName;

	/** All tracks in this binding */
	UPROPERTY()
	TArray<UMovieSceneTrack*> Tracks;
};
