#pragma once

#include <vector>
#include <utility>
#include "Core/ImGuiFramework.h"

/**
 * @brief The main class of the program
 * 
 */
class Application : public ImGuiFramework
{
public:
    /**
     * @brief Construct a new Application object to pass basic info
     * 
     */
    Application() = default;

    /**
     * @brief Cleanup when the app is closed
     * 
     */
    ~Application() = default;

    /**
     * @brief Configure the application (mainly ImGui)
     * 
     */
    virtual void StartUp() final;

    /**
     * @brief The main loop of the program
     * 
     */
    virtual void Update() final;

private:
    void CheckValueChange();
    
    void CalculateSinWave();
    void CalculateDefSinWave();
    void CalculateSquareWave();
    void CalculateDiracWave();
    void CalculateSawWave();


private:
    int Duration = 10;
    int PrevDuration = 10;

    float SinPeakValue = 1.0f;
    float PrevSinPeakValue = 1.0f;
    float SinFrequency = 1.0f;
    float PrevSinFrequency = 1.0f;
    int SinPhaseShift = 0;
    int PrevSinPhaseShift = 0;

    float SqValueA = 1.0f;
    float PrevSqValueA = 1.0f;
    float SqValueB = -1.0f;
    float PrevSqValueB = -1.0f;
    float SqFrequency = 1.0f;
    float PrevSqFrequency = 1.0f;
    int SqPhaseShift = 0;
    int PrevSqPhaseShift = 0;
    float DutyCycle = 50.0f;
    float PrevDutyCycle = 50.0f;
    int SqIterations = 100;
    int PrevSqIterations = 100;

    float DiracFrequency = 1.0f;
    float PrevDiracFrequency = 1.0f;
    int DiracPhaseShift = 0;
    int PrevDiracPhaseShift = 0;
    int DiracIterations = 50;
    int PrevDiracIterations = 50;

    float SawValueA = 1.0f;
    float PrevSawValueA = 1.0f;
    float SawValueB = 0.0f;
    float PrevSawValueB = 0.0f;
    float SawFrequency = 1.0f;
    float PrevSawFrequency = 1.0f;
    int SawPhaseShift = 0;
    int PrevSawPhaseShift = 0;
    int SawIterations = 100;
    int PrevSawIterations = 100;

    std::pair<std::vector<float>, std::vector<float>> SinWave;
    std::pair<std::vector<float>, std::vector<float>> DefSinWave;
    std::pair<std::vector<float>, std::vector<float>> SqWave;
    std::pair<std::vector<float>, std::vector<float>> DirWave;
    std::pair<std::vector<float>, std::vector<float>> SaWave;
};