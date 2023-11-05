#pragma once

#include "Event.h"

namespace Little {

    class LITTLE_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        inline unsigned int GetWidth() const { return m_Width;}
        inline unsigned int GetHeight()const { return m_Height;}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
            return ss.str();
        }

        //EVENT_CLASS_TYPE(WindowResize)
        static EventType GetStaticType() { return EventType::WindowResize;}\
            virtual EventType GetEventType() const override { return GetStaticType();}\
            virtual const char* GetName() const override { return "WindowResize";}
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        unsigned int m_Width, m_Height;
    };

    class LITTLE_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class LITTLE_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    };

    class LITTLE_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    };
}
