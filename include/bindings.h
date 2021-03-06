#ifndef RIVER_BINDINGS_H
#define RIVER_BINDINGS_H

#include <wlr/backend/session.h>

/*
 * This header is needed since zig cannot yet translate flexible arrays.
 * See https://github.com/ziglang/zig/issues/4775
 */

struct wlr_backend_impl;

struct wlr_backend {
	const struct wlr_backend_impl *impl;

	struct {
		/** Raised when destroyed, passed the wlr_backend reference */
		struct wl_signal destroy;
		/** Raised when new inputs are added, passed the wlr_input_device */
		struct wl_signal new_input;
		/** Raised when new outputs are added, passed the wlr_output */
		struct wl_signal new_output;
	} events;
};

struct wlr_backend *river_wlr_backend_autocreate(struct wl_display *display);
struct wlr_renderer *river_wlr_backend_get_renderer(struct wlr_backend *backend);
bool river_wlr_backend_start(struct wlr_backend *backend);
bool river_wlr_backend_is_multi(struct wlr_backend *backend);
struct wlr_session *river_wlr_backend_get_session(struct wlr_backend *backend);
struct wlr_backend *river_wlr_noop_backend_create(struct wl_display *display);
struct wlr_output *river_wlr_noop_add_output(struct wlr_backend *backend);
bool river_wlr_output_is_noop(struct wlr_output *output);
void river_wlr_backend_destory(struct wlr_backend *backend);

#endif // RIVER_BINDINGS_H
