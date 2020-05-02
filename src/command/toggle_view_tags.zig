// This file is part of river, a dynamic tiling wayland compositor.
//
// Copyright 2020 Isaac Freund
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

const c = @import("../c.zig");

const Arg = @import("../command.zig").Arg;
const Seat = @import("../Seat.zig");

/// Toggle the passed tags of the focused view
pub fn toggleViewTags(seat: *Seat, arg: Arg) void {
    const tags = arg.uint;
    if (seat.focused_view) |view| {
        const new_tags = view.current_tags ^ tags;
        if (new_tags != 0) {
            view.pending_tags = new_tags;
            seat.input_manager.server.root.arrange();
        }
    }
}
