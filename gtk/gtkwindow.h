/* GTK - The GIMP Toolkit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#pragma once


#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkapplication.h>
#include <gtk/gtkaccelgroup.h>
#include <gtk/gtkwidget.h>

G_BEGIN_DECLS

#define GTK_TYPE_WINDOW			(gtk_window_get_type ())
#define GTK_WINDOW(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_WINDOW, GtkWindow))
#define GTK_WINDOW_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_WINDOW, GtkWindowClass))
#define GTK_IS_WINDOW(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_WINDOW))
#define GTK_IS_WINDOW_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_WINDOW))
#define GTK_WINDOW_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_WINDOW, GtkWindowClass))

typedef struct _GtkWindowClass        GtkWindowClass;
typedef struct _GtkWindowGroup        GtkWindowGroup;
typedef struct _GtkWindowGroupClass   GtkWindowGroupClass;
typedef struct _GtkWindowGroupPrivate GtkWindowGroupPrivate;

struct _GtkWindow
{
  GtkWidget parent_instance;
};

/**
 * GtkWindowClass:
 * @parent_class: The parent class.
 * @activate_focus: Activates the current focused widget within the window.
 * @activate_default: Activates the default widget for the window.
 * @keys_changed: Signal gets emitted when the set of accelerators or
 *   mnemonics that are associated with window changes.
 * @enable_debugging: Class handler for the `GtkWindow::enable-debugging`
 *   keybinding signal.
 */
struct _GtkWindowClass
{
  GtkWidgetClass parent_class;

  /*< public >*/

  /* G_SIGNAL_ACTION signals for keybindings */

  void     (* activate_focus)   (GtkWindow *window);
  void     (* activate_default) (GtkWindow *window);
  void	   (* keys_changed)     (GtkWindow *window);
  gboolean (* enable_debugging) (GtkWindow *window,
                                 gboolean   toggle);
  /**
   * GtkWindowClass::close_request:
   *
   * Class handler for the [signal@Window::close-request] signal.
   *
   * Returns: Whether the window should be destroyed
   */
  gboolean (* close_request)    (GtkWindow *window);

  /*< private >*/
  gpointer padding[8];
};

GDK_AVAILABLE_IN_ALL
GType      gtk_window_get_type                 (void) G_GNUC_CONST;
GDK_AVAILABLE_IN_ALL
GtkWidget* gtk_window_new                      (void);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_title                (GtkWindow           *window,
						const char          *title);
GDK_AVAILABLE_IN_ALL
const char * gtk_window_get_title             (GtkWindow           *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_startup_id           (GtkWindow           *window,
                                                const char          *startup_id);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_focus                (GtkWindow           *window,
						GtkWidget           *focus);
GDK_AVAILABLE_IN_ALL
GtkWidget *gtk_window_get_focus                (GtkWindow           *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_default_widget       (GtkWindow           *window,
						GtkWidget           *default_widget);
GDK_AVAILABLE_IN_ALL
GtkWidget *gtk_window_get_default_widget       (GtkWindow           *window);

GDK_AVAILABLE_IN_ALL
void       gtk_window_set_transient_for        (GtkWindow           *window,
						GtkWindow           *parent);
GDK_AVAILABLE_IN_ALL
GtkWindow *gtk_window_get_transient_for        (GtkWindow           *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_destroy_with_parent  (GtkWindow           *window,
                                                gboolean             setting);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_destroy_with_parent  (GtkWindow           *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_hide_on_close        (GtkWindow           *window,
                                                gboolean             setting);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_hide_on_close        (GtkWindow           *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_mnemonics_visible    (GtkWindow           *window,
                                                gboolean             setting);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_mnemonics_visible    (GtkWindow           *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_focus_visible        (GtkWindow           *window,
                                                gboolean             setting);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_focus_visible        (GtkWindow           *window);

GDK_AVAILABLE_IN_ALL
void       gtk_window_set_resizable            (GtkWindow           *window,
                                                gboolean             resizable);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_resizable            (GtkWindow           *window);

GDK_AVAILABLE_IN_ALL
void	   gtk_window_set_display              (GtkWindow	    *window,
						GdkDisplay          *display);

GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_is_active                (GtkWindow           *window);

GDK_AVAILABLE_IN_ALL
void       gtk_window_set_decorated            (GtkWindow *window,
                                                gboolean   setting);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_decorated            (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_deletable            (GtkWindow *window,
                                                gboolean   setting);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_deletable            (GtkWindow *window);

GDK_AVAILABLE_IN_ALL
void       gtk_window_set_icon_name                (GtkWindow   *window,
						    const char *name);
GDK_AVAILABLE_IN_ALL
const char * gtk_window_get_icon_name             (GtkWindow  *window);
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_default_icon_name        (const char *name);
GDK_AVAILABLE_IN_ALL
const char * gtk_window_get_default_icon_name     (void);

GDK_AVAILABLE_IN_ALL
void       gtk_window_set_auto_startup_notification (gboolean setting);

/* If window is set modal, input will be grabbed when show and released when hide */
GDK_AVAILABLE_IN_ALL
void       gtk_window_set_modal      (GtkWindow *window,
				      gboolean   modal);
GDK_AVAILABLE_IN_ALL
gboolean   gtk_window_get_modal      (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
GListModel *gtk_window_get_toplevels (void);
GDK_AVAILABLE_IN_ALL
GList*     gtk_window_list_toplevels (void);

GDK_AVAILABLE_IN_ALL
void     gtk_window_present            (GtkWindow *window);
GDK_DEPRECATED_IN_4_14_FOR(gtk_window_present)
void     gtk_window_present_with_time  (GtkWindow *window,
				        guint32    timestamp);
GDK_AVAILABLE_IN_ALL
void     gtk_window_minimize      (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
void     gtk_window_unminimize    (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
void     gtk_window_maximize      (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
void     gtk_window_unmaximize    (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
void     gtk_window_fullscreen    (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
void     gtk_window_unfullscreen  (GtkWindow *window);
GDK_AVAILABLE_IN_ALL
void     gtk_window_fullscreen_on_monitor (GtkWindow  *window,
                                           GdkMonitor *monitor);
GDK_AVAILABLE_IN_ALL
void     gtk_window_close         (GtkWindow *window);

/* Set initial default size of the window (does not constrain user
 * resize operations)
 */
GDK_AVAILABLE_IN_ALL
void     gtk_window_set_default_size (GtkWindow   *window,
                                      int          width,
                                      int          height);
GDK_AVAILABLE_IN_ALL
void     gtk_window_get_default_size (GtkWindow   *window,
                                      int         *width,
                                      int         *height);

GDK_AVAILABLE_IN_ALL
GtkWindowGroup *gtk_window_get_group (GtkWindow   *window);
GDK_AVAILABLE_IN_ALL
gboolean gtk_window_has_group        (GtkWindow   *window);


GDK_AVAILABLE_IN_ALL
GtkApplication *gtk_window_get_application      (GtkWindow          *window);
GDK_AVAILABLE_IN_ALL
void            gtk_window_set_application      (GtkWindow          *window,
                                                 GtkApplication     *application);

GDK_AVAILABLE_IN_ALL
void     gtk_window_set_child              (GtkWindow    *window,
                                            GtkWidget    *child);
GDK_AVAILABLE_IN_ALL
GtkWidget *gtk_window_get_child            (GtkWindow    *window);

GDK_AVAILABLE_IN_ALL
void     gtk_window_set_titlebar           (GtkWindow    *window,
                                            GtkWidget    *titlebar);
GDK_AVAILABLE_IN_ALL
GtkWidget *gtk_window_get_titlebar         (GtkWindow    *window);

GDK_AVAILABLE_IN_ALL
gboolean gtk_window_is_maximized           (GtkWindow    *window);

GDK_AVAILABLE_IN_ALL
gboolean gtk_window_is_fullscreen          (GtkWindow    *window);

GDK_AVAILABLE_IN_4_12
gboolean gtk_window_is_suspended           (GtkWindow    *window);

GDK_AVAILABLE_IN_ALL
void     gtk_window_destroy                (GtkWindow    *window);

GDK_AVAILABLE_IN_ALL
void     gtk_window_set_interactive_debugging (gboolean enable);

GDK_AVAILABLE_IN_4_2
void     gtk_window_set_handle_menubar_accel (GtkWindow *window,
                                              gboolean   handle_menubar_accel);
GDK_AVAILABLE_IN_4_2
gboolean gtk_window_get_handle_menubar_accel (GtkWindow *window);

/**
 * GtkWindowGravity:
 * @GTK_WINDOW_GRAVITY_TOP_LEFT: The top left corner
 * @GTK_WINDOW_GRAVITY_TOP: The top edge
 * @GTK_WINDOW_GRAVITY_TOP_RIGHT: The top right corner
 * @GTK_WINDOW_GRAVITY_LEFT: The left edge
 * @GTK_WINDOW_GRAVITY_CENTER: The center pointer
 * @GTK_WINDOW_GRAVITY_RIGHT: The right edge
 * @GTK_WINDOW_GRAVITY_BOTTOM_LEFT: The bottom left corner
 * @GTK_WINDOW_GRAVITY_BOTTOM: the bottom edge
 * @GTK_WINDOW_GRAVITY_BOTTOM_RIGHT: The bottom right corner
 * @GTK_WINDOW_GRAVITY_TOP_START: The top left or top right corner,
 *   depending on the text direction
 * @GTK_WINDOW_GRAVITY_TOP_END: The top right or top left corner,
 *   depending on the text direction
 * @GTK_WINDOW_GRAVITY_START: The left or right edge,
 *   depending on the text direction
 * @GTK_WINDOW_GRAVITY_END: The right or left edge,
 *   depending on the text direction
 * @GTK_WINDOW_GRAVITY_BOTTOM_START: The bottom left or top right corner,
 *   depending on the text direction
 * @GTK_WINDOW_GRAVITY_BOTTOM_END: The bottom right or top left corner,
 *   depending on the text direction
 *
 * Determines which point or edge of a window is meant to remain fixed
 * when a window changes size.
 *
 * Since: 4.20
 */
typedef enum
{
  GTK_WINDOW_GRAVITY_TOP_LEFT,
  GTK_WINDOW_GRAVITY_TOP,
  GTK_WINDOW_GRAVITY_TOP_RIGHT,
  GTK_WINDOW_GRAVITY_LEFT,
  GTK_WINDOW_GRAVITY_CENTER,
  GTK_WINDOW_GRAVITY_RIGHT,
  GTK_WINDOW_GRAVITY_BOTTOM_LEFT,
  GTK_WINDOW_GRAVITY_BOTTOM,
  GTK_WINDOW_GRAVITY_BOTTOM_RIGHT,
  GTK_WINDOW_GRAVITY_TOP_START,
  GTK_WINDOW_GRAVITY_TOP_END,
  GTK_WINDOW_GRAVITY_START,
  GTK_WINDOW_GRAVITY_END,
  GTK_WINDOW_GRAVITY_BOTTOM_START,
  GTK_WINDOW_GRAVITY_BOTTOM_END,
} GtkWindowGravity;

GDK_AVAILABLE_IN_4_20
GtkWindowGravity
         gtk_window_get_gravity              (GtkWindow        *window);
GDK_AVAILABLE_IN_4_20
void     gtk_window_set_gravity              (GtkWindow        *window,
                                              GtkWindowGravity  gravity);

G_DEFINE_AUTOPTR_CLEANUP_FUNC(GtkWindow, g_object_unref)
G_DEFINE_AUTOPTR_CLEANUP_FUNC(GtkWindowGroup, g_object_unref)

G_END_DECLS

