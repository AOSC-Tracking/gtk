/* gdkdrmtoplevelsurface.c
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

#include "config.h"

#include "gdkdrmtoplevelsurface-private.h"

#include "gdkframeclockidleprivate.h"
#include "gdkseatprivate.h"
#include "gdktoplevelprivate.h"

#include "gdkdrmdisplay-private.h"
#include "gdkdrmmonitor-private.h"

static gboolean
_gdk_drm_toplevel_surface_compute_size (GdkSurface *surface)
{
  g_assert (GDK_IS_DRM_TOPLEVEL_SURFACE (surface));

  return FALSE;
}

static void
_gdk_drm_toplevel_surface_present (GdkToplevel       *toplevel,
                                   GdkToplevelLayout *layout)
{
  g_assert (GDK_IS_DRM_TOPLEVEL_SURFACE (toplevel));
}

static gboolean
_gdk_drm_toplevel_surface_minimize (GdkToplevel *toplevel)
{
  return FALSE;
}

static gboolean
_gdk_drm_toplevel_surface_lower (GdkToplevel *toplevel)
{
  return FALSE;
}

static void
_gdk_drm_toplevel_surface_focus (GdkToplevel *toplevel,
                                 guint32      timestamp)
{
}

static void
_gdk_drm_toplevel_surface_begin_resize (GdkToplevel    *toplevel,
                                        GdkSurfaceEdge  edge,
                                        GdkDevice      *device,
                                        int             button,
                                        double          root_x,
                                        double          root_y,
                                        guint32         timestamp)
{
  g_assert (GDK_IS_DRM_SURFACE (toplevel));
}

static void
_gdk_drm_toplevel_surface_begin_move (GdkToplevel *toplevel,
                                      GdkDevice   *device,
                                      int          button,
                                      double       root_x,
                                      double       root_y,
                                      guint32      timestamp)
{
  g_assert (GDK_IS_DRM_SURFACE (toplevel));
}

static void
toplevel_iface_init (GdkToplevelInterface *iface)
{
  iface->present = _gdk_drm_toplevel_surface_present;
  iface->minimize = _gdk_drm_toplevel_surface_minimize;
  iface->lower = _gdk_drm_toplevel_surface_lower;
  iface->focus = _gdk_drm_toplevel_surface_focus;
  iface->begin_resize = _gdk_drm_toplevel_surface_begin_resize;
  iface->begin_move = _gdk_drm_toplevel_surface_begin_move;
}

G_DEFINE_TYPE_WITH_CODE (GdkDrmToplevelSurface, _gdk_drm_toplevel_surface, GDK_TYPE_DRM_SURFACE,
                         G_IMPLEMENT_INTERFACE (GDK_TYPE_TOPLEVEL, toplevel_iface_init))

enum {
  PROP_0,
  LAST_PROP
};

static void
_gdk_drm_toplevel_surface_hide (GdkSurface *surface)
{
  GDK_SURFACE_CLASS (_gdk_drm_toplevel_surface_parent_class)->hide (surface);
}

static void
_gdk_drm_toplevel_surface_request_layout (GdkSurface *surface)
{
}

static void
_gdk_drm_toplevel_surface_destroy (GdkSurface *surface,
                                   gboolean    foreign_destroy)
{
  GDK_SURFACE_CLASS (_gdk_drm_toplevel_surface_parent_class)->destroy (surface, foreign_destroy);
}

static void
_gdk_drm_toplevel_surface_get_property (GObject    *object,
                                          guint       prop_id,
                                          GValue     *value,
                                          GParamSpec *pspec)
{
  GdkSurface *surface = GDK_SURFACE (object);

  switch (prop_id)
    {
    case LAST_PROP + GDK_TOPLEVEL_PROP_STATE:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_TITLE:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_STARTUP_ID:
      g_value_set_string (value, "");
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_TRANSIENT_FOR:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_MODAL:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_ICON_LIST:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_DECORATED:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_DELETABLE:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_FULLSCREEN_MODE:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_SHORTCUTS_INHIBITED:
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

static void
_gdk_drm_toplevel_surface_set_property (GObject      *object,
                                          guint         prop_id,
                                          const GValue *value,
                                          GParamSpec   *pspec)
{
  switch (prop_id)
    {
    case LAST_PROP + GDK_TOPLEVEL_PROP_TITLE:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_STARTUP_ID:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_TRANSIENT_FOR:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_MODAL:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_ICON_LIST:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_DECORATED:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_DELETABLE:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_FULLSCREEN_MODE:
      break;

    case LAST_PROP + GDK_TOPLEVEL_PROP_SHORTCUTS_INHIBITED:
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

static void
_gdk_drm_toplevel_surface_constructed (GObject *object)
{
  G_OBJECT_CLASS (_gdk_drm_toplevel_surface_parent_class)->constructed (object);
}

static void
_gdk_drm_toplevel_surface_class_init (GdkDrmToplevelSurfaceClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GdkSurfaceClass *surface_class = GDK_SURFACE_CLASS (klass);

  object_class->constructed = _gdk_drm_toplevel_surface_constructed;
  object_class->get_property = _gdk_drm_toplevel_surface_get_property;
  object_class->set_property = _gdk_drm_toplevel_surface_set_property;

  surface_class->destroy = _gdk_drm_toplevel_surface_destroy;
  surface_class->hide = _gdk_drm_toplevel_surface_hide;
  surface_class->compute_size = _gdk_drm_toplevel_surface_compute_size;
  surface_class->request_layout = _gdk_drm_toplevel_surface_request_layout;

  gdk_toplevel_install_properties (object_class, LAST_PROP);
}

static void
_gdk_drm_toplevel_surface_init (GdkDrmToplevelSurface *self)
{
}
