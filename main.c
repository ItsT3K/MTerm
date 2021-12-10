/* mterm is a little terminal program based upon a Writing your own Terminal tutorial by
Vincent Bernat. This terminal is based off of the VTE libraries found in GNOME terminal
and other terminals.

Other modifications are made however and not everything is stock to that of the original
Vincent Bernat terminal code.*/

#include <vte/vte.h>
#include <gtk/gtk.h>
#define CLR_R(x) (((x)&0xff0000) >> 16)
#define CLR_G(x) (((x)&0x00ff00) >> 8)
#define CLR_B(x) (((x)&0x0000ff) >> 0)
#define CLR_16(x) ((double)(x) / 0xff)
#define CLR_GDK(x) (const GdkRGBA){.red = CLR_16(CLR_R(x)),    \
                                   .green = CLR_16(CLR_G(x)),    \
                                   .blue = CLR_16(CLR_B(x)),    \
                                   .alpha = 0}

static gboolean
on_title_changed(GtkWidget *terminal, gpointer user_data) {
    GtkWindow *window = user_data;
    gtk_window_set_title(window,
                         vte_terminal_get_window_title(VTE_TERMINAL(terminal)) ?: "Terminal");
    return TRUE;
}

int
main(int argc, char *argv[]) {
    GtkWidget *window, *terminal;
    /* Initialise GTK, the window and the terminal */
    gtk_init(&argc, &argv);
    terminal = vte_terminal_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "mterm");        //MTERM TESTING NAME

    /* Start a new shell */
    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]) {g_strdup(g_environ_getenv(envp, "SHELL")), NULL};
    g_strfreev(envp);
    vte_terminal_spawn_async(VTE_TERMINAL(terminal),
                             VTE_PTY_DEFAULT,
                             NULL,       /* working directory  */
                             command,    /* command */
                             NULL,       /* environment */
                             0,          /* spawn flags */
                             NULL, NULL, /* child setup */
                             NULL,       /* child pid */
                             -1,         /* timeout */
                             NULL, NULL, NULL);
/*GTK Font. The DEC TERMINAL Font is required by default. But you can change this to whatever
font you please*/
    PangoContext *context = pango_context_new();
    PangoFontDescription *desc = pango_font_description_from_string("pixifont2 13");
    PangoFontMap *pfm = pango_cairo_font_map_get_default();
    PangoFont *font = pango_font_map_load_font(pfm, context, desc);
    vte_terminal_set_font(terminal, desc);

    /* Connect some signals */
    g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
    g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);
    g_signal_connect(terminal, "window-title-changed",
                     G_CALLBACK(on_title_changed), GTK_WINDOW(window));
    /* Put widgets together and run the main loop */
    gtk_container_add(GTK_CONTAINER(window), terminal);
    gtk_widget_show_all(window);

    /*Set Window Icon*/
    gtk_window_set_icon_from_file(GTK_WINDOW(window), ICONPATH, NULL);
/*Set the terminal colors*/
    vte_terminal_set_colors(VTE_TERMINAL(terminal),
                            &CLR_GDK(0xffffff),
                            &(GdkRGBA) {.alpha = 0.85},
                            (const GdkRGBA[]) {
                                    CLR_GDK(0x111111),
                                    CLR_GDK(0xd36265),
                                    CLR_GDK(0xaece91),
                                    CLR_GDK(0xe7e18c),
                                    CLR_GDK(0x5297cf),
                                    CLR_GDK(0x963c59),
                                    CLR_GDK(0x5E7175),
                                    CLR_GDK(0xbebebe),
                                    CLR_GDK(0x666666),
                                    CLR_GDK(0xef8171),
                                    CLR_GDK(0xcfefb3),
                                    CLR_GDK(0xfff796),
                                    CLR_GDK(0x74b8ef),
                                    CLR_GDK(0xb85e7b),
                                    CLR_GDK(0xA3BABF),
                                    CLR_GDK(0xffffff)
                            }, 16);
/*Set the cursor color*/
	vte_terminal_set_color_cursor(VTE_TERMINAL(terminal), &CLR_GDK(0xaece91));
	vte_terminal_set_color_cursor_foreground(VTE_TERMINAL(terminal), &CLR_GDK(0x0000ff));
	
	/*Set Terminal Size*/
	vte_terminal_set_size (VTE_TERMINAL(terminal), 80, 24);
	
	/*Set Font Scale*/
	vte_terminal_set_font_scale (VTE_TERMINAL(terminal), 0.95);
                        

	/*Features*/
		vte_terminal_set_scrollback_lines(VTE_TERMINAL(terminal), 0);
		vte_terminal_set_scroll_on_output(VTE_TERMINAL(terminal), FALSE);
		vte_terminal_set_scroll_on_keystroke(VTE_TERMINAL(terminal), TRUE);
		vte_terminal_set_mouse_autohide(VTE_TERMINAL(terminal), TRUE);
		vte_terminal_set_audible_bell(terminal, TRUE);
		vte_terminal_set_rewrap_on_resize (VTE_TERMINAL(terminal), TRUE);
		vte_terminal_set_cursor_blink_mode (VTE_TERMINAL(terminal), TRUE);
		vte_terminal_set_scroll_on_keystroke (VTE_TERMINAL(terminal), TRUE);
		
    /*Put widgets together and run main loop*/
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(terminal));
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();

    gtk_main();
}
