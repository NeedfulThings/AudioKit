//
//  OCSGrain.h
//  Objective-Csound
//
//  Created by Adam Boulanger on 6/21/12.
//  Copyright (c) 2012 Hear For Yourself. All rights reserved.
//

#import "OCSOpcode.h"

/**  Generates granular synthesis textures.
*/

@interface OCSGrain : OCSOpcode

/// @name Properties

/// The output is an audio signal.
@property (nonatomic, retain) OCSParameter *output;

/// @name Initialization

/// Instantiates the grain synthesis with the given parameters.
/// @param amplitude              Amplitude of each grain.
/// @param grainFrequency         To use the original frequency of the input sound, divide the original sample rate of the grain waveform by the length of the grain function table.
/// @param grainDensity           Density of grains measured in grains per second. If this is constant then the output is synchronous granular synthesis. If grainDensity has a random element (like added noise), then the result is more like asynchronous granular synthesis.
/// @param maxAmplitudeDeviation  Maximum amplitude deviation from `amplitude`. If it is set to zero then there is no random amplitude for each grain.
/// @param maxPitchDeviation      Maximum pitch deviation from grainPitch in Hz.
/// @param grainDuration          Grain duration in seconds. 
/// @param maxGrainDuration       Maximum grain duration in seconds.
/// @param grainFunction          The grain waveform. This can be just a sine wave or a sampled sound.
/// @param windowFunction         The amplitude envelope used for the grains.
- (id)initWithGrainFunction:(OCSFTable *)grainFunction
             windowFunction:(OCSFTable *)windowFunction
           maxGrainDuration:(OCSConstant *)maxGrainDuration
                  amplitude:(OCSParameter *)amplitude
             grainFrequency:(OCSParameter *)grainFrequency
               grainDensity:(OCSParameter *)grainDensity  
              grainDuration:(OCSControl *)grainDuration
      maxAmplitudeDeviation:(OCSControl *)maxAmplitudeDeviation
          maxPitchDeviation:(OCSControl *)maxPitchDeviation;

- (void) turnOffGrainOffsetRandomnes;

@end
