/* LedBorgServer.c generated by valac 0.16.1, the Vala compiler
 * generated from LedBorgServer.vala, do not modify */

/* LedBorgServer.vala
 *
 * Copyright (C) 2013  Ross Taylor
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author:
 * 	Ross Taylor <the.mighty.ug@gmail.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <libsoup/soup.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LED_BORG_TYPE_LED_BORG_SERVER (led_borg_led_borg_server_get_type ())
#define LED_BORG_LED_BORG_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LED_BORG_TYPE_LED_BORG_SERVER, LedBorgLedBorgServer))
#define LED_BORG_LED_BORG_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LED_BORG_TYPE_LED_BORG_SERVER, LedBorgLedBorgServerClass))
#define LED_BORG_IS_LED_BORG_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LED_BORG_TYPE_LED_BORG_SERVER))
#define LED_BORG_IS_LED_BORG_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LED_BORG_TYPE_LED_BORG_SERVER))
#define LED_BORG_LED_BORG_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LED_BORG_TYPE_LED_BORG_SERVER, LedBorgLedBorgServerClass))

typedef struct _LedBorgLedBorgServer LedBorgLedBorgServer;
typedef struct _LedBorgLedBorgServerClass LedBorgLedBorgServerClass;
typedef struct _LedBorgLedBorgServerPrivate LedBorgLedBorgServerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define LED_BORG_TYPE_COLOUR (led_borg_colour_get_type ())
typedef struct _LedBorgColour LedBorgColour;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _led_borg_colour_free0(var) ((var == NULL) ? NULL : (var = (led_borg_colour_free (var), NULL)))

struct _LedBorgLedBorgServer {
	SoupServer parent_instance;
	LedBorgLedBorgServerPrivate * priv;
};

struct _LedBorgLedBorgServerClass {
	SoupServerClass parent_class;
};

struct _LedBorgColour {
	gint red;
	gint green;
	gint blue;
};

typedef enum  {
	IO_ERROR_FILE_NOT_FOUND,
	IO_ERROR_COMMUNICATION_BREAKDOWN,
	IO_ERROR_GENERAL
} IOError;
#define IO_ERROR io_error_quark ()
typedef enum  {
	REQUEST_ERROR_COLOUR_REQUEST_INVALID,
	REQUEST_ERROR_GENERAL
} RequestError;
#define REQUEST_ERROR request_error_quark ()

static gpointer led_borg_led_borg_server_parent_class = NULL;

GType led_borg_led_borg_server_get_type (void) G_GNUC_CONST;
enum  {
	LED_BORG_LED_BORG_SERVER_DUMMY_PROPERTY
};
LedBorgLedBorgServer* led_borg_led_borg_server_new (void);
LedBorgLedBorgServer* led_borg_led_borg_server_construct (GType object_type);
LedBorgLedBorgServer* led_borg_led_borg_server_new_with_listen_port (gint listen_port);
LedBorgLedBorgServer* led_borg_led_borg_server_construct_with_listen_port (GType object_type, gint listen_port);
void led_borg_led_borg_server_initialize_server (LedBorgLedBorgServer* self);
void led_borg_led_borg_server_handler_default (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client);
static void _led_borg_led_borg_server_handler_default_soup_server_callback (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client, gpointer self);
void led_borg_led_borg_server_handler_get_colour (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client);
static void _led_borg_led_borg_server_handler_get_colour_soup_server_callback (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client, gpointer self);
void led_borg_led_borg_server_handler_set_colour (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client);
static void _led_borg_led_borg_server_handler_set_colour_soup_server_callback (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client, gpointer self);
GType led_borg_colour_get_type (void) G_GNUC_CONST;
LedBorgColour* led_borg_colour_dup (const LedBorgColour* self);
void led_borg_colour_free (LedBorgColour* self);
GQuark io_error_quark (void);
void led_borg_device_get_colour (LedBorgColour* result, GError** error);
void led_borg_responder_respond_with_colour (SoupMessage** msg, LedBorgColour* colour);
void led_borg_responder_respond_with_error (SoupMessage** msg, const gchar* error_message);
GQuark request_error_quark (void);
static LedBorgColour* led_borg_led_borg_server_get_colour_from_query (GHashTable* query, GError** error);
void led_borg_device_set_colour (LedBorgColour* colour, GError** error);


LedBorgLedBorgServer* led_borg_led_borg_server_construct (GType object_type) {
	LedBorgLedBorgServer * self = NULL;
	self = (LedBorgLedBorgServer*) g_object_new (object_type, NULL);
	return self;
}


LedBorgLedBorgServer* led_borg_led_borg_server_new (void) {
	return led_borg_led_borg_server_construct (LED_BORG_TYPE_LED_BORG_SERVER);
}


LedBorgLedBorgServer* led_borg_led_borg_server_construct_with_listen_port (GType object_type, gint listen_port) {
	LedBorgLedBorgServer * self = NULL;
	gint _tmp0_;
	FILE* _tmp1_;
	guint _tmp2_;
	guint _tmp3_;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_;
	_tmp0_ = listen_port;
	self = (LedBorgLedBorgServer*) g_object_new (object_type, "port", _tmp0_, NULL);
	_tmp1_ = stderr;
	_tmp2_ = soup_server_get_port ((SoupServer*) self);
	_tmp3_ = _tmp2_;
	_tmp4_ = g_strdup_printf ("%u", _tmp3_);
	_tmp5_ = _tmp4_;
	fprintf (_tmp1_, "listening on port %s\n", _tmp5_);
	_g_free0 (_tmp5_);
	led_borg_led_borg_server_initialize_server (self);
	return self;
}


LedBorgLedBorgServer* led_borg_led_borg_server_new_with_listen_port (gint listen_port) {
	return led_borg_led_borg_server_construct_with_listen_port (LED_BORG_TYPE_LED_BORG_SERVER, listen_port);
}


static void _led_borg_led_borg_server_handler_default_soup_server_callback (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client, gpointer self) {
	led_borg_led_borg_server_handler_default (server, msg, path, query, client);
}


static void _led_borg_led_borg_server_handler_get_colour_soup_server_callback (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client, gpointer self) {
	led_borg_led_borg_server_handler_get_colour (server, msg, path, query, client);
}


static void _led_borg_led_borg_server_handler_set_colour_soup_server_callback (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client, gpointer self) {
	led_borg_led_borg_server_handler_set_colour (server, msg, path, query, client);
}


void led_borg_led_borg_server_initialize_server (LedBorgLedBorgServer* self) {
	g_return_if_fail (self != NULL);
	soup_server_add_handler ((SoupServer*) self, "/", _led_borg_led_borg_server_handler_default_soup_server_callback, NULL, NULL);
	soup_server_add_handler ((SoupServer*) self, "/GetColour", _led_borg_led_borg_server_handler_get_colour_soup_server_callback, NULL, NULL);
	soup_server_add_handler ((SoupServer*) self, "/SetColour", _led_borg_led_borg_server_handler_set_colour_soup_server_callback, NULL, NULL);
}


void led_borg_led_borg_server_handler_default (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client) {
	g_return_if_fail (server != NULL);
	g_return_if_fail (msg != NULL);
	g_return_if_fail (path != NULL);
	g_return_if_fail (client != NULL);
}


void led_borg_led_borg_server_handler_get_colour (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (server != NULL);
	g_return_if_fail (msg != NULL);
	g_return_if_fail (path != NULL);
	g_return_if_fail (client != NULL);
	{
		LedBorgColour _tmp0_ = {0};
		LedBorgColour current_colour;
		LedBorgColour _tmp1_;
		led_borg_device_get_colour (&_tmp0_, &_inner_error_);
		current_colour = _tmp0_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == IO_ERROR) {
				goto __catch1_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp1_ = current_colour;
		led_borg_responder_respond_with_colour (&msg, &_tmp1_);
	}
	goto __finally1;
	__catch1_io_error:
	{
		GError* e = NULL;
		FILE* _tmp2_;
		GError* _tmp3_;
		const gchar* _tmp4_;
		GError* _tmp5_;
		const gchar* _tmp6_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp2_ = stderr;
		_tmp3_ = e;
		_tmp4_ = _tmp3_->message;
		fprintf (_tmp2_, "IO Error: %s\n", _tmp4_);
		_tmp5_ = e;
		_tmp6_ = _tmp5_->message;
		led_borg_responder_respond_with_error (&msg, _tmp6_);
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void led_borg_led_borg_server_handler_set_colour (SoupServer* server, SoupMessage* msg, const gchar* path, GHashTable* query, SoupClientContext* client) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (server != NULL);
	g_return_if_fail (msg != NULL);
	g_return_if_fail (path != NULL);
	g_return_if_fail (client != NULL);
	{
		GHashTable* _tmp0_;
		LedBorgColour* _tmp1_ = NULL;
		LedBorgColour* colour;
		LedBorgColour* _tmp2_;
		_tmp0_ = query;
		_tmp1_ = led_borg_led_borg_server_get_colour_from_query (_tmp0_, &_inner_error_);
		colour = _tmp1_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == REQUEST_ERROR) {
				goto __catch2_request_error;
			}
			if (_inner_error_->domain == IO_ERROR) {
				goto __catch2_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp2_ = colour;
		if (_tmp2_ != NULL) {
			LedBorgColour* _tmp3_;
			LedBorgColour _tmp4_;
			LedBorgColour* _tmp5_;
			LedBorgColour _tmp6_;
			_tmp3_ = colour;
			_tmp4_ = *_tmp3_;
			led_borg_device_set_colour (&_tmp4_, &_inner_error_);
			if (_inner_error_ != NULL) {
				_led_borg_colour_free0 (colour);
				if (_inner_error_->domain == REQUEST_ERROR) {
					goto __catch2_request_error;
				}
				if (_inner_error_->domain == IO_ERROR) {
					goto __catch2_io_error;
				}
				_led_borg_colour_free0 (colour);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			_tmp5_ = colour;
			_tmp6_ = *_tmp5_;
			led_borg_responder_respond_with_colour (&msg, &_tmp6_);
		}
		_led_borg_colour_free0 (colour);
	}
	goto __finally2;
	__catch2_request_error:
	{
		GError* e = NULL;
		FILE* _tmp7_;
		GError* _tmp8_;
		const gchar* _tmp9_;
		GError* _tmp10_;
		const gchar* _tmp11_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp7_ = stderr;
		_tmp8_ = e;
		_tmp9_ = _tmp8_->message;
		fprintf (_tmp7_, "Request Error: %s\n", _tmp9_);
		_tmp10_ = e;
		_tmp11_ = _tmp10_->message;
		led_borg_responder_respond_with_error (&msg, _tmp11_);
		_g_error_free0 (e);
	}
	goto __finally2;
	__catch2_io_error:
	{
		GError* e = NULL;
		FILE* _tmp12_;
		GError* _tmp13_;
		const gchar* _tmp14_;
		GError* _tmp15_;
		const gchar* _tmp16_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp12_ = stderr;
		_tmp13_ = e;
		_tmp14_ = _tmp13_->message;
		fprintf (_tmp12_, "IO Error: %s\n", _tmp14_);
		_tmp15_ = e;
		_tmp16_ = _tmp15_->message;
		led_borg_responder_respond_with_error (&msg, _tmp16_);
		_g_error_free0 (e);
	}
	__finally2:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static gpointer _led_borg_colour_dup0 (gpointer self) {
	return self ? led_borg_colour_dup (self) : NULL;
}


static LedBorgColour* led_borg_led_borg_server_get_colour_from_query (GHashTable* query, GError** error) {
	LedBorgColour* result = NULL;
	LedBorgColour* colour;
	GHashTable* _tmp0_;
	GError * _inner_error_ = NULL;
	colour = NULL;
	_tmp0_ = query;
	if (_tmp0_ != NULL) {
		gboolean _tmp1_ = FALSE;
		gboolean _tmp2_ = FALSE;
		GHashTable* _tmp3_;
		gconstpointer _tmp4_ = NULL;
		gboolean _tmp7_;
		gboolean _tmp10_;
		_tmp3_ = query;
		_tmp4_ = g_hash_table_lookup (_tmp3_, "red");
		if (((const gchar*) _tmp4_) != NULL) {
			GHashTable* _tmp5_;
			gconstpointer _tmp6_ = NULL;
			_tmp5_ = query;
			_tmp6_ = g_hash_table_lookup (_tmp5_, "green");
			_tmp2_ = ((const gchar*) _tmp6_) != NULL;
		} else {
			_tmp2_ = FALSE;
		}
		_tmp7_ = _tmp2_;
		if (_tmp7_) {
			GHashTable* _tmp8_;
			gconstpointer _tmp9_ = NULL;
			_tmp8_ = query;
			_tmp9_ = g_hash_table_lookup (_tmp8_, "blue");
			_tmp1_ = ((const gchar*) _tmp9_) != NULL;
		} else {
			_tmp1_ = FALSE;
		}
		_tmp10_ = _tmp1_;
		if (_tmp10_) {
			{
				GHashTable* _tmp11_;
				gconstpointer _tmp12_ = NULL;
				gint _tmp13_ = 0;
				GHashTable* _tmp14_;
				gconstpointer _tmp15_ = NULL;
				gint _tmp16_ = 0;
				GHashTable* _tmp17_;
				gconstpointer _tmp18_ = NULL;
				gint _tmp19_ = 0;
				LedBorgColour _tmp20_ = {0};
				LedBorgColour* _tmp21_;
				_tmp11_ = query;
				_tmp12_ = g_hash_table_lookup (_tmp11_, "red");
				_tmp13_ = atoi ((const gchar*) _tmp12_);
				_tmp14_ = query;
				_tmp15_ = g_hash_table_lookup (_tmp14_, "green");
				_tmp16_ = atoi ((const gchar*) _tmp15_);
				_tmp17_ = query;
				_tmp18_ = g_hash_table_lookup (_tmp17_, "blue");
				_tmp19_ = atoi ((const gchar*) _tmp18_);
				memset (&_tmp20_, 0, sizeof (LedBorgColour));
				_tmp20_.red = _tmp13_;
				_tmp20_.green = _tmp16_;
				_tmp20_.blue = _tmp19_;
				_tmp21_ = _led_borg_colour_dup0 (&_tmp20_);
				_led_borg_colour_free0 (colour);
				colour = _tmp21_;
			}
			goto __finally3;
			__catch3_g_error:
			{
				GError* e = NULL;
				GError* _tmp22_;
				const gchar* _tmp23_;
				gchar* _tmp24_ = NULL;
				gchar* _tmp25_;
				GError* _tmp26_;
				GError* _tmp27_;
				e = _inner_error_;
				_inner_error_ = NULL;
				_tmp22_ = e;
				_tmp23_ = _tmp22_->message;
				_tmp24_ = g_strdup_printf ("Failed to create colour from parameters: %s", _tmp23_);
				_tmp25_ = _tmp24_;
				_tmp26_ = g_error_new_literal (REQUEST_ERROR, REQUEST_ERROR_COLOUR_REQUEST_INVALID, _tmp25_);
				_tmp27_ = _tmp26_;
				_g_free0 (_tmp25_);
				_inner_error_ = _tmp27_;
				_g_error_free0 (e);
				goto __finally3;
			}
			__finally3:
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == REQUEST_ERROR) {
					g_propagate_error (error, _inner_error_);
					_led_borg_colour_free0 (colour);
					return NULL;
				} else {
					_led_borg_colour_free0 (colour);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
					g_clear_error (&_inner_error_);
					return NULL;
				}
			}
		} else {
			GError* _tmp28_;
			_tmp28_ = g_error_new_literal (REQUEST_ERROR, REQUEST_ERROR_COLOUR_REQUEST_INVALID, "Incorrect parameters");
			_inner_error_ = _tmp28_;
			if (_inner_error_->domain == REQUEST_ERROR) {
				g_propagate_error (error, _inner_error_);
				_led_borg_colour_free0 (colour);
				return NULL;
			} else {
				_led_borg_colour_free0 (colour);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
		}
	} else {
		GError* _tmp29_;
		_tmp29_ = g_error_new_literal (REQUEST_ERROR, REQUEST_ERROR_COLOUR_REQUEST_INVALID, "No parameters found");
		_inner_error_ = _tmp29_;
		if (_inner_error_->domain == REQUEST_ERROR) {
			g_propagate_error (error, _inner_error_);
			_led_borg_colour_free0 (colour);
			return NULL;
		} else {
			_led_borg_colour_free0 (colour);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	result = colour;
	return result;
}


static void led_borg_led_borg_server_class_init (LedBorgLedBorgServerClass * klass) {
	led_borg_led_borg_server_parent_class = g_type_class_peek_parent (klass);
}


static void led_borg_led_borg_server_instance_init (LedBorgLedBorgServer * self) {
}


GType led_borg_led_borg_server_get_type (void) {
	static volatile gsize led_borg_led_borg_server_type_id__volatile = 0;
	if (g_once_init_enter (&led_borg_led_borg_server_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LedBorgLedBorgServerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) led_borg_led_borg_server_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LedBorgLedBorgServer), 0, (GInstanceInitFunc) led_borg_led_borg_server_instance_init, NULL };
		GType led_borg_led_borg_server_type_id;
		led_borg_led_borg_server_type_id = g_type_register_static (soup_server_get_type (), "LedBorgLedBorgServer", &g_define_type_info, 0);
		g_once_init_leave (&led_borg_led_borg_server_type_id__volatile, led_borg_led_borg_server_type_id);
	}
	return led_borg_led_borg_server_type_id__volatile;
}



