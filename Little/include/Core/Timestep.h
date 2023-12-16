#pragma once

namespace Little {

    class Timestep
    {
    public:
        Timestep(float time = 0.0f)
            : m_Time(time)
        {

        }
    private:
        float m_Time;
    };
}