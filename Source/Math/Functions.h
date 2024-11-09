#pragma once

#include <cmath>
#include <vector>
#include <utility>

#define PI 3.14159265358979323846

std::pair<std::vector<float>, std::vector<float>> SinusWave(float PeakValue, float Frequency, int PhaseShift, int Duration);
std::pair<std::vector<float>, std::vector<float>> SquareWave(float ValueA, float ValueB, float Frequency, int PhaseShift, float DutyCycle, int Iterations, int Duration);
std::pair<std::vector<float>, std::vector<float>> DiracWave(float Frequency, int PhaseShift, int Iterations, int Duration);
std::pair<std::vector<float>, std::vector<float>> SawWave(float ValueA, float ValueB, float Frequency, int PhaseShift, int Iterations, int Duration);
std::pair<std::vector<float>, std::vector<float>> FourierTransform(int Iterations, int Duration);