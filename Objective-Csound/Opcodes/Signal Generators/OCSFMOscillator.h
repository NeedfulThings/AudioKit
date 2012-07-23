//
//  OCSFMOscillator.h
//  Objective-Csound
//
//  Created by Adam Boulanger on 5/29/12.
//  Copyright (c) 2012 MIT Media Lab. All rights reserved.
//

#import "OCSOpcode.h"

/** Basic frequency modulated oscillator with linear interpolation.

Interpolating generators will produce a noticeably cleaner output signal, but
they may take as much as twice as long to run. Adequate accuracy can also be
gained without the time cost of interpolation by using large stored function
tables of 2K, 4K or 8K points if the space is available.  

http://www.csounds.com/manual/html/foscili.html
*/

@interface OCSFMOscillator : OCSOpcode 

/// @name Properties

/// The output is mono audio signal.
@property (nonatomic, strong) OCSParameter *output;

/// The amplitude of the output signal.
@property (nonatomic, strong) OCSParameter *amplitude;

/// In cycles per second, or Hz, this is the common denominator for the carrier and modulating frequencies.
@property (nonatomic, strong) OCSControl *baseFrequency;

/// This multiplied by the baseFrequency gives the carrier frequency.
@property (nonatomic, strong) OCSParameter *carrierMultiplier;

/// This multiplied by the baseFrequency gives the modulating frequency.
@property (nonatomic, strong) OCSParameter *modulatingMultiplier;

/// This multiplied by the modulating frequency gives the modulation amplitude.
@property (nonatomic, strong) OCSControl *modulationIndex;

/// Function table to use.  Requires a wrap-around guard point.
@property (nonatomic, strong) OCSFTable *fTable;

/// Initial phase of waveform in fTable, expressed as a fraction of a cycle (0 to 1). 
/// A negative value will cause phase initialization to be skipped.
@property (nonatomic, strong) OCSControl *phase;

/// @name Initialization

/// Initializes a frequency modulated oscillator with linear interpolation.
/// @param amplitude            The amplitude of the output signal.
/// @param baseFrequency        In cycles per second, or Hz, this is the common denominator for the carrier and modulating frequencies.
/// @param carrierMultiplier    This multiplied by the baseFrequency gives the carrier frequency.
/// @param modulatingMultiplier This multiplied by the baseFrequency gives the modulating frequency.
/// @param modulationIndex      This multiplied by the modulating frequency gives the modulation amplitude.
/// @param fTable        Function table to use.  Requires a wrap-around guard point.
/// @param phase                Initial phase of waveform in fTable, expressed as a fraction of a cycle (0 to 1). 
/// A negative value will cause phase initialization to be skipped.
- (id)initWithAmplitude:(OCSParameter *)amplitude
          baseFrequency:(OCSControl *)baseFrequency
      carrierMultiplier:(OCSParameter *)carrierMultiplier
   modulatingMultiplier:(OCSParameter *)modulatingMultiplier
        modulationIndex:(OCSControl *)modulationIndex
                 fTable:(OCSFTable *)fTable
                  phase:(OCSConstant *)phase;

/// Initializes a frequency modulated oscillator with linear interpolation with no phasing.
/// @param amplitude            The amplitude of the output signal.
/// @param baseFrequency        In cycles per second, or Hz, this is the common denominator for the carrier and modulating frequencies.
/// @param carrierMultiplier    This multiplied by the baseFrequency gives the carrier frequency.
/// @param modulatingMultiplier This multiplied by the baseFrequency gives the modulating frequency.
/// @param modulationIndex      This multiplied by the modulating frequency gives the modulation amplitude.
/// @param fTable        Function table to use.  Requires a wrap-around guard point.
- (id)initWithAmplitude:(OCSParameter *)amplitude
          baseFrequency:(OCSControl *)baseFrequency
      carrierMultiplier:(OCSParameter *)carrierMultiplier
   modulatingMultiplier:(OCSParameter *)modulatingMultiplier
        modulationIndex:(OCSControl *)modulationIndex
                 fTable:(OCSFTable *)fTable;




@end
