/*
 *  terminal.c
 * 
 *  Copyright (C) 2004, 2005 Free Software Foundation, Inc.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Author: Christian Neumair <chris@gnome-de.org>
 * 
 */

#ifdef HAVE_CONFIG_H
 #include <config.h>
#endif

#include "nautilus-terminal.h"

#include <gconf/gconf-client.h>
#include <libintl.h>

static GType type_list[1];

void
nautilus_module_initialize (GTypeModule *module)
{
	g_print ("Initializing nautilus-terminal extension\n");

	nautilus_terminal_register_type (module);
	type_list[0] = NAUTILUS_TYPE_OPEN_TERMINATOR;

	bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");

        gconf_client_add_dir(gconf_client_get_default(), 
                             "/desktop/gnome/lockdown",
                             0,
                             NULL);
}

void
nautilus_module_shutdown (void)
{
	g_print ("Shutting down nautilus-terminal extension\n");
}

void 
nautilus_module_list_types (const GType **types,
			    int          *num_types)
{
	*types = type_list;
	*num_types = G_N_ELEMENTS (type_list);
}
