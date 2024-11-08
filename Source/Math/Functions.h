#pragma once

#include <cmath>
#include <vector>
#include <utility>

std::pair<std::vector<float>, std::vector<float>> SinusWave(float PeakValue, float Frequency, int PhaseShift, int Duration)
{
    int DataAmount = Duration * 1000;

    std::vector<float> x_data;
    std::vector<float> y_data;
    for (int i = 0; i < DataAmount; i++)
    {
        x_data.push_back(i / 1000.0f);
        y_data.push_back(PeakValue * sin(Frequency * 2 * 3.1415f * x_data[i] + (PhaseShift * 3.1415f / 180)));
    }

    return std::make_pair(x_data, y_data);
}

std::pair<std::vector<float>, std::vector<float>> SquareWave(float ValueA, float ValueB, float Frequency, int PhaseShift, float DutyCycle, int Iterations, int Duration)
{
    float T = 1 / Frequency;
    int DataAmount = Duration * 1000;
    float PhaseShiftRad = PhaseShift * 3.1415f / 180;

    float a0 = ValueA * DutyCycle / 100 + ValueB * (1 - DutyCycle / 100);

    std::vector<float> x_data;
    std::vector<float> y_data;
    
    for (int i = 0; i < DataAmount; i++)
    {
        x_data.push_back(i / 1000.0f);
        y_data.push_back(a0);
    
        for (int n = 1; n <= Iterations; n++)
        {
            float an = (2 / T) * (ValueA * (sin(n * 3.1415f * DutyCycle / 50) / (2 * n * 3.1415f / T)) + ValueB * ((sin(n * 3.1415f * 2) / (2 * n * 3.1415f / T)) - (sin(n * 3.1415f * DutyCycle / 50) / (2 * n * 3.1415f / T))));
            float bn = (2 / T) * (ValueA * ((1 / (2 * n * 3.1415f / T)) - (cos(n * 3.1415f * DutyCycle / 50) / (2 * n * 3.1415f / T))) + ValueB * ((cos(n * 3.1415f * DutyCycle / 50) / (2 * n * 3.1415f / T)) - (cos(2 * n * 3.1415f) / (2* n * 3.1415f / T))));

            float An = sqrt(an * an + bn * bn);
            float FinalPhaseShift = atan2(bn, an);

            y_data[i] += An * cos(2 * n * 3.1415f / T * x_data[i] - FinalPhaseShift + PhaseShiftRad * n);
        }
    }

    return std::make_pair(x_data, y_data);
}

std::pair<std::vector<float>, std::vector<float>> DiracWave(float Frequency, int PhaseShift, int Iterations, int Duration)
{
    float T = 1 / Frequency;
    int DataAmount = Duration * 1000;
    float PhaseShiftRad = (PhaseShift - 180) * 3.1415f / 180;

    std::vector<float> x_data;
    std::vector<float> y_data;

    for (int i = 0; i < DataAmount; i++)
    {
        x_data.push_back(i / 1000.0f);
        y_data.push_back(1 / T);

        for (int n = -Iterations; n <= Iterations; n++)
        {
            y_data[i] += (2 * cos((2 * n * 3.1415f / T) * x_data[i] + n * PhaseShiftRad));
        }
    }

    return std::make_pair(x_data, y_data);
}

std::pair<std::vector<float>, std::vector<float>> SawWave(float ValueA, float ValueB, float Frequency, int PhaseShift, int Iterations, int Duration)
{
    float T = 1 / Frequency;
    int DataAmount = Duration * 1000;
    float PhaseShiftRad = (PhaseShift - 180) * 3.1415f / 180;

    float a0 = (ValueA + ValueB) / 2;

    std::vector<float> x_data;
    std::vector<float> y_data;

    for (int i = 0; i < DataAmount; i++)
    {
        x_data.push_back(i / 1000.0f);
        y_data.push_back(a0);

        for (int n = 1; n <= Iterations; n++)
        {
            y_data[i] += ((ValueA - ValueB) / 3.1415f) * (pow(-1, n + 1) / n) * sin((2 * n * 3.1415f / T) * x_data[i] + n * PhaseShiftRad);
        }
    }

    return std::make_pair(x_data, y_data);
}