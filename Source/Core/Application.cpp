#include "Platform.h"
#ifdef PLATFORM_WINDOWS
    #include <Windows.h>
#endif
#include "Core/Application.h"
#include "Math/Functions.h"

/**
 * @brief Configure the application and do initial calculations (in this case, calculate the waves)
 * 
 */
void Application::StartUp()
{
    CalculateSinWave();
    CalculateDefSinWave();
    CalculateSquareWave();
    CalculateDiracWave();
    CalculateSawWave();
}

/**
 * @brief The main loop of the program (here I display the waves, their parameters and allow the user to change them)
 * 
 */
void Application::Update()
{  
    const int Spacing = 10;
    const int DataAmount = Duration * 1000;

    float x_data[DataAmount];
    float y_data[DataAmount];
    float x_data_def[DataAmount];
    float y_data_def[DataAmount];
    float x_data_square[DataAmount];
    float y_data_square[DataAmount];
    float x_data_dirac[DataAmount];
    float y_data_dirac[DataAmount];
    float x_data_saw[DataAmount];
    float y_data_saw[DataAmount];
    for (int i = 0; i < DataAmount; i++)
    {
        x_data[i] = std::get<0>(SinWave)[i];
        y_data[i] = std::get<1>(SinWave)[i];
        x_data_def[i] = std::get<0>(DefSinWave)[i];
        y_data_def[i] = std::get<1>(DefSinWave)[i];
        x_data_square[i] = std::get<0>(SqWave)[i];
        y_data_square[i] = std::get<1>(SqWave)[i];
        x_data_dirac[i] = std::get<0>(DirWave)[i];
        y_data_dirac[i] = std::get<1>(DirWave)[i];
        x_data_saw[i] = std::get<0>(SaWave)[i];
        y_data_saw[i] = std::get<1>(SaWave)[i];
    }

    ImGui::InputInt("Duration [s]", &Duration);
    if (Duration < 1) Duration = 1;
    if (Duration > 100) Duration = 100;

    for (int i = 0; i < Spacing; i++) ImGui::Spacing();

    ImGui::InputFloat("Peak Value [V]", &SinPeakValue);
    if (SinPeakValue < 0) SinPeakValue = 0;
    ImGui::InputFloat("Angular Frequency [rad/s]", &SinFrequency);
    if (SinFrequency <= 0) SinFrequency = 1;
    ImGui::InputInt("Phase Shift [°]", &SinPhaseShift);
    if (SinPhaseShift > 360) SinPhaseShift = 360;
    if (SinPhaseShift < -360) SinPhaseShift = -360;

    if (ImPlot::BeginPlot("Sine Wave")) 
    {
        ImPlot::SetupAxes("t[s]", "U[V]");
        ImPlot::PlotLine("u(t)", x_data, y_data, DataAmount);
        ImPlot::PlotLine("u(t) - Default", x_data_def, y_data_def, DataAmount);
        ImPlot::EndPlot();
    }

    for (int i = 0; i < Spacing; i++) ImGui::Spacing();

    ImGui::InputFloat("Value A [V]", &SqValueA);
    ImGui::InputFloat("Value B [V]", &SqValueB);
    ImGui::InputFloat("Angular Frequency [rad/s]##2", &SqFrequency);
    if (SqFrequency <= 0) SqFrequency = 1;
    ImGui::InputInt("Phase Shift [°]##2", &SqPhaseShift);
    if (SqPhaseShift > 360) SqPhaseShift = 360;
    if (SqPhaseShift < -360) SqPhaseShift = -360;
    ImGui::InputFloat("Duty Cycle [%]", &DutyCycle);
    if (DutyCycle > 100) DutyCycle = 100;
    if (DutyCycle < 0) DutyCycle = 0;
    ImGui::InputInt("Iterations", &SqIterations);
    if (SqIterations < 1) SqIterations = 1;
    if (SqIterations > 1000000) SqIterations = 1000000;

    if (ImPlot::BeginPlot("Square Wave")) 
    {
        ImPlot::SetupAxes("t[s]", "U[V]");
        ImPlot::PlotLine("u(t)", x_data_square, y_data_square, DataAmount);
        ImPlot::EndPlot();
    }

    for (int i = 0; i < Spacing; i++) ImGui::Spacing();
    
    ImGui::InputFloat("Angular Frequency [rad/s]##3", &DiracFrequency);
    if (DiracFrequency <= 0) DiracFrequency = 1;
    ImGui::InputInt("Phase Shift [°]##3", &DiracPhaseShift);
    if (DiracPhaseShift > 360) DiracPhaseShift = 360;
    if (DiracPhaseShift < -360) DiracPhaseShift = -360;
    ImGui::InputInt("Iterations##2", &DiracIterations);
    if (DiracIterations < 1) DiracIterations = 1;

    if (ImPlot::BeginPlot("Dirac Impulse Wave")) 
    {
        ImPlot::SetupAxes("t[s]", "U[V]");
        ImPlot::PlotLine("u(t)", x_data_dirac, y_data_dirac, DataAmount);
        ImPlot::EndPlot();
    }

    for (int i = 0; i < Spacing; i++) ImGui::Spacing();

    ImGui::InputFloat("Value A [V]##3", &SawValueA);
    ImGui::InputFloat("Value B [V]##3", &SawValueB);
    ImGui::InputFloat("Angular Frequency [rad/s]##4", &SawFrequency);
    if (SawFrequency <= 0) SawFrequency = 1;
    ImGui::InputInt("Phase Shift [°]##4", &SawPhaseShift);
    if (SawPhaseShift > 360) SawPhaseShift = 360;
    if (SawPhaseShift < -360) SawPhaseShift = -360;
    ImGui::InputInt("Iterations##3", &SawIterations);
    if (SawIterations < 1) SawIterations = 1;

    if (ImPlot::BeginPlot("Sawtooth Wave")) 
    {
        ImPlot::SetupAxes("t[s]", "U[V]");
        ImPlot::PlotLine("u(t)", x_data_saw, y_data_saw, DataAmount);
        ImPlot::EndPlot();
    }

    CheckValueChange();
}

void Application::CheckValueChange()
{
    bool IsSinRecalculated = false;
    bool IsDefSinRecalculated = false;
    bool IsSquareRecalculated = false;
    bool IsDiracRecalculated = false;
    bool IsSawRecalculated = false;

    if (Duration != PrevDuration)
    {
        CalculateSinWave();
        IsSinRecalculated = true;

        CalculateDefSinWave();
        IsDefSinRecalculated = true;

        CalculateSquareWave();
        IsSquareRecalculated = true;

        CalculateDiracWave();
        IsDiracRecalculated = true;

        CalculateSawWave();
        IsSawRecalculated = true;

        PrevDuration = Duration;
    }

    if (SinPeakValue != PrevSinPeakValue || SinFrequency != PrevSinFrequency || SinPhaseShift != PrevSinPhaseShift)
    {
        if (!IsSinRecalculated)
        {
            CalculateSinWave();
            IsSinRecalculated = true;
        }

        PrevSinPeakValue = SinPeakValue;
        PrevSinFrequency = SinFrequency;
        PrevSinPhaseShift = SinPhaseShift;
    }

    if (SqValueA != PrevSqValueA || SqValueB != PrevSqValueB || SqFrequency != PrevSqFrequency || SqPhaseShift != PrevSqPhaseShift || DutyCycle != PrevDutyCycle || SqIterations != PrevSqIterations)
    {
        if (!IsSquareRecalculated)
        {
            CalculateSquareWave();
            IsSquareRecalculated = true;
        }

        PrevSqValueA = SqValueA;
        PrevSqValueB = SqValueB;
        PrevSqFrequency = SqFrequency;
        PrevSqPhaseShift = SqPhaseShift;
        PrevDutyCycle = DutyCycle;
        PrevSqIterations = SqIterations;
    }

    if (DiracFrequency != PrevDiracFrequency || DiracPhaseShift != PrevDiracPhaseShift || DiracIterations != PrevDiracIterations)
    {
        if (!IsDefSinRecalculated)
        {
            CalculateDiracWave();
            IsDiracRecalculated = true;
        }

        PrevDiracFrequency = DiracFrequency;
        PrevDiracPhaseShift = DiracPhaseShift;
        PrevDiracIterations = DiracIterations;
    }

    if (SawValueA != PrevSawValueA || SawValueB != PrevSawValueB || SawFrequency != PrevSawFrequency || SawPhaseShift != PrevSawPhaseShift || SawIterations != PrevSawIterations)
    {
        if (!IsSawRecalculated)
        {
            CalculateSawWave();
            IsSawRecalculated = true;
        }

        PrevSawValueA = SawValueA;
        PrevSawValueB = SawValueB;
        PrevSawFrequency = SawFrequency;
        PrevSawPhaseShift = SawPhaseShift;
        PrevSawIterations = SawIterations;
    }
}

void Application::CalculateSinWave()
{
    SinWave = SinusWave(SinPeakValue, SinFrequency, SinPhaseShift, Duration);
}

void Application::CalculateDefSinWave()
{
    DefSinWave = SinusWave(1, 1, 0, Duration);
}

void Application::CalculateSquareWave()
{
    SqWave = SquareWave(SqValueA, SqValueB, SqFrequency, SqPhaseShift, DutyCycle, SqIterations, Duration);
}

void Application::CalculateDiracWave()
{
    DirWave = DiracWave(DiracFrequency, DiracPhaseShift, DiracIterations, Duration);
}

void Application::CalculateSawWave()
{
    SaWave = SawWave(SawValueA, SawValueB, SawFrequency, SawPhaseShift, SawIterations, Duration);
}
