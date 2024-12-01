/* gdkdrmkeymap.h
 *
 * Copyright 2024 Christian Hergert <chergert@redhat.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#pragma once

#if !defined (__GDKDRM_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gdk/drm/gdkdrm.h> can be included directly."
#endif

#include <gdk/gdk.h>

G_BEGIN_DECLS

typedef struct _GdkDrmKeymap      GdkDrmKeymap;
typedef struct _GdkDrmKeymapClass GdkDrmKeymapClass;

#define GDK_TYPE_DRM_KEYMAP       (gdk_drm_keymap_get_type())
#define GDK_DRM_KEYMAP(object)    (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_DRM_KEYMAP, GdkDrmKeymap))
#define GDK_IS_DRM_KEYMAP(object) (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_DRM_KEYMAP))

GDK_AVAILABLE_IN_ALL
GType gdk_drm_keymap_get_type (void);

G_END_DECLS

