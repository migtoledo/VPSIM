#pragma once

// SCREEN-FRAME EVENTS (WINDOW)
void scrframeevents()
{
	(al_wait_for_event_until(ScrEventsQueue, &ScrEvent, &timeout)) ?
		NewScrEvent = true : NewScrEvent = false;
	doactionsScrEvents(NewScrEvent);
}

// MOUSE EVENTS
void mouseevents()
{
	(al_wait_for_event_until(MouseEventsQueue, &MouseEvent, &timeout)) ?
		NewMouseEvent = true : NewMouseEvent = false;
	doactionsMouseEvents(NewMouseEvent);
}

// KEYBOARD EVENTS
void keyboardevents()
{	
	(al_wait_for_event_until(KeyboardEventsQueue, &KeyboardEvent, &timeout)) ?
		NewKeyboardEvent = true : NewKeyboardEvent = false;
	doactionsKeyboardEvents(NewKeyboardEvent);
}


// TIMER EVENTS
void timerevents()
{
	(al_wait_for_event_until(TimerEventsQueue, &TimerEvent, &timeout)) ?
		NewTimerEvent = true : NewTimerEvent = false;
	doactionsTimerEvents(NewTimerEvent);
}