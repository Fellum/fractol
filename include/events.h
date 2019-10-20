#ifndef EVENTS_H
# define EVENTS_H

int	key_press(int key, t_inputstate *state);
int key_release(int key, t_inputstate *state);
int	close_event(t_fract *data);
int	draw_tick(t_fract *data);

#endif
