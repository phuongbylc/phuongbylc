#include "ImpTimer.h"
#include "CommonFunc.h"
ImpTimer::ImpTimer()
{
    start_tick_ = 0;
    paused_tick_ = 0;
    is_paused_ = false;
    is_started_ = false;
}

ImpTimer::~ImpTimer()
{

}

void ImpTimer::Start()
{
    is_paused_ = false;
    is_started_ = true;
    start_tick_ = SDL_GetTicks();

}

void ImpTimer::Stop()
{
    is_paused_ = false;
    is_started_ = false;
}

void ImpTimer::paused()
{
    if(is_started_ == true && is_paused_ == false)
    {
        is_paused_ = true;
        paused_tick_ = SDL_GetTicks() - start_tick_;

    }
}

void ImpTimer::resume()
{
    if(is_paused_ == true)
    {
        is_paused_ = false;
        start_tick_ = SDL_GetTicks() - paused_tick_;
        paused_tick_ = 0;
    }
}

int ImpTimer::get_ticks()
{
    if(is_started_ == true)
    {
        if(is_paused_ == true)
        {
            return paused_tick_;
        }
        else
        {
                    return SDL_GetTicks() - start_tick_;
        
        }
    }
    return 0;
}

bool is_started_()
{
    return is_started_;
}

bool is_paused_()
{
    return is_paused_;
}



