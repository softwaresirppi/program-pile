#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define C1 16.35
#define C2 32.7
#define C3 65.41
#define C4 130.81
#define C5 261.63
#define C6 523.25
#define C7 1046.5
#define C8 2093
#define C9 4186
#define CSharp1 17.32
#define CSharp2 34.65
#define CSharp3 69.3
#define CSharp4 138.59
#define CSharp5 277.18
#define CSharp6 554.37
#define CSharp7 1108.73
#define CSharp8 2217.46
#define CSharp9 4434.92
#define D1 18.35
#define D2 36.71
#define D3 73.42
#define D4 146.83
#define D5 293.66
#define D6 587.33
#define D7 1174.66
#define D8 2349.32
#define D9 4698.63
#define DSharp1 19.45
#define DSharp2 38.89
#define DSharp3 77.78
#define DSharp4 155.56
#define DSharp5 311.13
#define DSharp6 622.25
#define DSharp7 1244.51
#define DSharp8 2489
#define DSharp9 4978
#define E1 20.6
#define E2 41.2
#define E3 82.41
#define E4 164.81
#define E5 329.63
#define E6 659.25
#define E7 1318.51
#define E8 2637
#define E9 5274
#define F1 21.83
#define F2 43.65
#define F3 87.31
#define F4 174.61
#define F5 349.23
#define F6 698.46
#define F7 1396.91
#define F8 2793.83
#define F9 5587.65
#define FSharp1 23.12
#define FSharp2 46.25
#define FSharp3 92.5
#define FSharp4 185
#define FSharp5 369.99
#define FSharp6 739.99
#define FSharp7 1479.98
#define FSharp8 2959.96
#define FSharp9 5919.91
#define G1 24.5
#define G2 49
#define G3 98
#define G4 196
#define G5 392
#define G6 783.99
#define G7 1567.98
#define G8 3135.96
#define G9 6271.93
#define GSharp1 25.96
#define GSharp2 51.91
#define GSharp3 103.83
#define GSharp4 207.65
#define GSharp5 415.3
#define GSharp6 830.61
#define GSharp7 1661.22
#define GSharp8 3322.44
#define GSharp9 6644.88
#define A1 27.5
#define A2 55
#define A3 110
#define A4 220
#define A5 440
#define A6 880
#define A7 1760
#define A8 3520
#define A9 7040
#define ASharp1 29.14
#define ASharp2 58.27
#define ASharp3 116.54
#define ASharp4 233.08
#define ASharp5 466.16
#define ASharp6 932.33
#define ASharp7 1864.66
#define ASharp8 3729.31
#define ASharp9 7458.62
#define B1 30.87
#define B2 61.74
#define B3 123.47
#define B4 246.94
#define B5 493.88
#define B6 987.77
#define B7 1975.53
#define B8 3951
#define B9 7902.13

#define PI 3.14159265358979323846


void little_endian_32(uint32_t x){
	for(int i = 0; i < 4; i++){
		printf("%c", x % 256);
		x /= 256;
	}
}

void little_endian_16(uint16_t x){
	for(int i = 0; i < 2; i++){
		printf("%c", x % 256);
		x /= 256;
	}
}

uint32_t make_even(uint32_t x){
	return x + (x & 1);
}

typedef struct {
	double frequency;
	double snapshots;
} Tone;

void generate(Tone tone, int bitrate){
	for(int i = 0; i < tone.snapshots; i++)
		printf("%c", (int)round((sin(2 * PI * i * (tone.frequency/bitrate)) + 1) / 2) * 127);
}

int main() {
	int CHANNELS = 1; // Nc
	int FREQUENCY = 8000;// F
	int SAMPLE_BYTES = 1; // M # of bytes in a sample across a specific channel and snapshot

	Tone tones[] = {
		{D4, FREQUENCY * 0.5},
		{F4, FREQUENCY * 0.35},
		{D4, FREQUENCY * 0.25},
		{D4, FREQUENCY * 0.15},
		{G4, FREQUENCY * 0.25},
		{D4, FREQUENCY * 0.25},
		{C4, FREQUENCY * 0.25},

		{D4, FREQUENCY * 0.5},
		{A4, FREQUENCY * 0.35},
		{D4, FREQUENCY * 0.25},
		{D4, FREQUENCY * 0.15},
		{ASharp4, FREQUENCY * 0.25},
		{A4, FREQUENCY * 0.25},
		{F4, FREQUENCY * 0.25},

		{D4, FREQUENCY * 0.25},
		{A4, FREQUENCY * 0.25},
		{D5, FREQUENCY * 0.25},
		{D4, FREQUENCY * 0.15},
		{C4, FREQUENCY * 0.25},
		{C4, FREQUENCY * 0.15},

		{A4, FREQUENCY * 0.25},
		// {E4, FREQUENCY * 0.30},
		{D4, FREQUENCY * 0.5},
	};

	int SNAPSHOTS = 0; // Ns # of captures that happen across all channels
	for(int i = 0; i < sizeof(tones)/sizeof(Tone); i++) SNAPSHOTS += tones[i].snapshots;

	printf("RIFF");
	little_endian_32(make_even(4 + 24 + 8 + SAMPLE_BYTES * CHANNELS * SNAPSHOTS));
	printf("WAVE");
	printf("fmt ");
	little_endian_32(16);
	little_endian_16(1);
	little_endian_16(CHANNELS);
	little_endian_32(FREQUENCY);
	little_endian_32(FREQUENCY * SAMPLE_BYTES * CHANNELS);
	little_endian_16(SAMPLE_BYTES * CHANNELS);
	little_endian_16(8 * SAMPLE_BYTES);
	printf("data");
	little_endian_32(SAMPLE_BYTES * CHANNELS * SNAPSHOTS);

	for(int i = 0; i < sizeof(tones)/sizeof(Tone); i++)
		generate(tones[i], 8000);
	if((SAMPLE_BYTES * CHANNELS * SNAPSHOTS) & 1) printf("%c", 0);
}
