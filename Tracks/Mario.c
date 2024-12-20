// C:\Midi\overworld.mid
#include "midi.h"
static MidiNoteEvent_t track1Notes_[]={
	{0, 0x90, 86, 100},
	{454, 0x90, 86, 0},
	{0, 0x90, 82, 100},
	{340, 0x90, 82, 0},
	{0, 0x90, 77, 100},
	{113, 0x90, 77, 0},
	{0, 0x90, 76, 100},
	{113, 0x90, 76, 0},
	{113, 0x90, 77, 100},
	{113, 0x90, 77, 0},
	{0, 0x90, 79, 100},
	{568, 0x90, 79, 0},
	{-1, 0, 0}
};
static MidiNoteEvent_t track2Notes_[]={
	{0, 0x91, 72, 127},
	{454, 0x91, 81, 0},
	{340, 0x91, 69, 0},
	{113, 0x91, 72, 0},
	{113, 0x91, 71, 0},
	{113, 0x91, 69, 127},
	{113, 0x91, 72, 0},
	{568, 0x91, 74, 0},
	{-1, 0, 0}
};
static MidiNoteEvent_t track3Notes_[]={
	{0, 0x92, 58, 100},
	{454, 0x92, 58, 0},
	{0, 0x92, 53, 100},
	{340, 0x92, 53, 0},
	{0, 0x92, 50, 100},
	{113, 0x92, 50, 0},
	{0, 0x92, 48, 100},
	{113, 0x92, 48, 0},
	{113, 0x92, 50, 100},
	{113, 0x92, 50, 0},
	{0, 0x92, 52, 100},
	{568, 0x92, 52, 0},
	{0, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{284, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 44, 127},
	{113, 0x92, 44, 0},
	{113, 0x92, 43, 127},
	{681, 0x92, 43, 0},
	{0, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 44, 127},
	{170, 0x92, 44, 0},
	{284, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 48, 127},
	{170, 0x92, 48, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 44, 127},
	{170, 0x92, 44, 0},
	{284, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 48, 127},
	{170, 0x92, 48, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{7556, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 39, 127},
	{170, 0x92, 39, 0},
	{284, 0x92, 39, 127},
	{170, 0x92, 39, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 37, 127},
	{170, 0x92, 37, 0},
	{284, 0x92, 37, 127},
	{170, 0x92, 37, 0},
	{284, 0x92, 36, 127},
	{227, 0x92, 36, 0},
	{909, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{7556, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{284, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 44, 127},
	{113, 0x92, 44, 0},
	{113, 0x92, 43, 127},
	{681, 0x92, 43, 0},
	{0, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 44, 127},
	{170, 0x92, 44, 0},
	{284, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 48, 127},
	{170, 0x92, 48, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 44, 127},
	{170, 0x92, 44, 0},
	{284, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 45, 127},
	{170, 0x92, 45, 0},
	{284, 0x92, 46, 127},
	{170, 0x92, 46, 0},
	{284, 0x92, 47, 127},
	{170, 0x92, 47, 0},
	{284, 0x92, 48, 127},
	{170, 0x92, 48, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 43, 127},
	{170, 0x92, 43, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{56, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{7556, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 39, 127},
	{170, 0x92, 39, 0},
	{284, 0x92, 39, 127},
	{170, 0x92, 39, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{284, 0x92, 37, 127},
	{170, 0x92, 37, 0},
	{284, 0x92, 37, 127},
	{170, 0x92, 37, 0},
	{284, 0x92, 36, 127},
	{227, 0x92, 36, 0},
	{909, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{56, 0x92, 38, 127},
	{170, 0x92, 38, 0},
	{56, 0x92, 40, 127},
	{170, 0x92, 40, 0},
	{56, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 36, 127},
	{170, 0x92, 36, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{284, 0x92, 41, 127},
	{170, 0x92, 41, 0},
	{-1, 0, 0}
};
static MidiNoteEvent_t track4Notes_[]={
	{1685, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{45, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{49, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{45, 0x93, 73, 100},
	{113, 0x93, 82, 0},
	{45, 0x93, 73, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 73, 100},
	{56, 0x93, 82, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{37, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{113, 0x93, 73, 100},
	{374, 0x93, 82, 0},
	{113, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{45, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{37, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{49, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{45, 0x93, 80, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{37, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{49, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{49, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{45, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{37, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{37, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{49, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{45, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{60, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{71, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{49, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{49, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{49, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 80, 100},
	{113, 0x93, 72, 0},
	{45, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{60, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{49, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{60, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{49, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{49, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{37, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{37, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{37, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{45, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{37, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{49, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 81, 100},
	{11, 0x93, 72, 0},
	{18, 0x93, 72, 100},
	{15, 0x93, 81, 0},
	{22, 0x93, 72, 100},
	{18, 0x93, 81, 0},
	{22, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{34, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{56, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{45, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{34, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{37, 0x93, 79, 100},
	{113, 0x93, 70, 0},
	{34, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{56, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{30, 0x93, 79, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 79, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 79, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{7, 0x93, 72, 100},
	{15, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{37, 0x93, 81, 0},
	{45, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{37, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{56, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{34, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{30, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{30, 0x93, 79, 100},
	{113, 0x93, 70, 0},
	{45, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{56, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{34, 0x93, 79, 100},
	{56, 0x93, 72, 0},
	{113, 0x93, 72, 100},
	{49, 0x93, 79, 0},
	{56, 0x93, 79, 0},
	{0, 0x93, 72, 0},
	{11, 0x93, 79, 100},
	{30, 0x93, 72, 0},
	{34, 0x93, 79, 0},
	{113, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{22, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{454, 0x93, 82, 0},
	{1363, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{45, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{7310, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{45, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{49, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{45, 0x93, 73, 100},
	{113, 0x93, 82, 0},
	{45, 0x93, 73, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 73, 100},
	{56, 0x93, 82, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{37, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{113, 0x93, 73, 100},
	{374, 0x93, 82, 0},
	{113, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{45, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{37, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{49, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{45, 0x93, 80, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{37, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{49, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{49, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{45, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{37, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{37, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{49, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{45, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{60, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{71, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{49, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{49, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{49, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 80, 100},
	{113, 0x93, 72, 0},
	{45, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{60, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{49, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{60, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{49, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 83, 100},
	{113, 0x93, 74, 0},
	{49, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 83, 100},
	{56, 0x93, 74, 0},
	{37, 0x93, 82, 100},
	{113, 0x93, 74, 0},
	{37, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{37, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{45, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{37, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{49, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 81, 100},
	{11, 0x93, 72, 0},
	{18, 0x93, 72, 100},
	{15, 0x93, 81, 0},
	{22, 0x93, 72, 100},
	{18, 0x93, 81, 0},
	{22, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{34, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{56, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{45, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{34, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{37, 0x93, 79, 100},
	{113, 0x93, 70, 0},
	{34, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{56, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{30, 0x93, 79, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 79, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 79, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{49, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{56, 0x93, 82, 100},
	{56, 0x93, 74, 0},
	{34, 0x93, 74, 100},
	{113, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{56, 0x93, 74, 100},
	{56, 0x93, 82, 0},
	{45, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{7, 0x93, 72, 100},
	{15, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{37, 0x93, 81, 0},
	{45, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{37, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{56, 0x93, 71, 100},
	{56, 0x93, 80, 0},
	{34, 0x93, 71, 100},
	{113, 0x93, 80, 0},
	{30, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{56, 0x93, 80, 100},
	{56, 0x93, 71, 0},
	{30, 0x93, 79, 100},
	{113, 0x93, 70, 0},
	{45, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{56, 0x93, 70, 100},
	{56, 0x93, 79, 0},
	{34, 0x93, 79, 100},
	{56, 0x93, 72, 0},
	{113, 0x93, 72, 100},
	{49, 0x93, 79, 0},
	{56, 0x93, 79, 0},
	{0, 0x93, 72, 0},
	{11, 0x93, 79, 100},
	{30, 0x93, 72, 0},
	{34, 0x93, 79, 0},
	{113, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{37, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{22, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{30, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 81, 100},
	{56, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{454, 0x93, 82, 0},
	{1363, 0x93, 81, 100},
	{113, 0x93, 72, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{45, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{30, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{37, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{113, 0x93, 81, 0},
	{34, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{56, 0x93, 72, 100},
	{56, 0x93, 81, 0},
	{-1, 0, 0}
};

static MidiTrack_t tracks_[] = {track1Notes_, track2Notes_, track3Notes_, track4Notes_};
MidiFile_t midi_tune = {4, tracks_};
