/* LedBorgClient.c generated by valac 0.16.1, the Vala compiler
 * generated from LedBorgClient.vala, do not modify */

/* applet/LedBorgClient.vala
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
#include <stdlib.h>
#include <string.h>


#define LED_BORG_TYPE_LED_BORG_CLIENT (led_borg_led_borg_client_get_type ())
#define LED_BORG_LED_BORG_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LED_BORG_TYPE_LED_BORG_CLIENT, LedBorgLedBorgClient))
#define LED_BORG_LED_BORG_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LED_BORG_TYPE_LED_BORG_CLIENT, LedBorgLedBorgClientClass))
#define LED_BORG_IS_LED_BORG_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LED_BORG_TYPE_LED_BORG_CLIENT))
#define LED_BORG_IS_LED_BORG_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LED_BORG_TYPE_LED_BORG_CLIENT))
#define LED_BORG_LED_BORG_CLIENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LED_BORG_TYPE_LED_BORG_CLIENT, LedBorgLedBorgClientClass))

typedef struct _LedBorgLedBorgClient LedBorgLedBorgClient;
typedef struct _LedBorgLedBorgClientClass LedBorgLedBorgClientClass;
typedef struct _LedBorgLedBorgClientPrivate LedBorgLedBorgClientPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define LED_BORG_TYPE_COLOUR (led_borg_colour_get_type ())
typedef struct _LedBorgColour LedBorgColour;

struct _LedBorgLedBorgClient {
	GObject parent_instance;
	LedBorgLedBorgClientPrivate * priv;
};

struct _LedBorgLedBorgClientClass {
	GObjectClass parent_class;
};

struct _LedBorgLedBorgClientPrivate {
	SoupSessionAsync* session;
	gchar* _server_host;
	guint _server_port;
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

static gpointer led_borg_led_borg_client_parent_class = NULL;

GType led_borg_led_borg_client_get_type (void) G_GNUC_CONST;
#define LED_BORG_LED_BORG_CLIENT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), LED_BORG_TYPE_LED_BORG_CLIENT, LedBorgLedBorgClientPrivate))
enum  {
	LED_BORG_LED_BORG_CLIENT_DUMMY_PROPERTY,
	LED_BORG_LED_BORG_CLIENT_SERVER_HOST,
	LED_BORG_LED_BORG_CLIENT_SERVER_PORT
};
LedBorgLedBorgClient* led_borg_led_borg_client_new (const gchar* host, guint port);
LedBorgLedBorgClient* led_borg_led_borg_client_construct (GType object_type, const gchar* host, guint port);
void led_borg_led_borg_client_set_server_host (LedBorgLedBorgClient* self, const gchar* value);
void led_borg_led_borg_client_set_server_port (LedBorgLedBorgClient* self, guint value);
GType led_borg_colour_get_type (void) G_GNUC_CONST;
LedBorgColour* led_borg_colour_dup (const LedBorgColour* self);
void led_borg_colour_free (LedBorgColour* self);
static gchar* led_borg_led_borg_client_generate_url (LedBorgLedBorgClient* self, const gchar* action, LedBorgColour* colour);
const gchar* led_borg_led_borg_client_get_server_host (LedBorgLedBorgClient* self);
guint led_borg_led_borg_client_get_server_port (LedBorgLedBorgClient* self);
GQuark io_error_quark (void);
void led_borg_led_borg_client_get_colour_from_server (LedBorgLedBorgClient* self, LedBorgColour* result, GError** error);
void led_borg_colour_init_with_rgb (LedBorgColour *self, const gchar* rgb);
static void led_borg_led_borg_client_finalize (GObject* obj);
static void _vala_led_borg_led_borg_client_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_led_borg_led_borg_client_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


LedBorgLedBorgClient* led_borg_led_borg_client_construct (GType object_type, const gchar* host, guint port) {
	LedBorgLedBorgClient * self = NULL;
	const gchar* _tmp0_;
	guint _tmp1_;
	g_return_val_if_fail (host != NULL, NULL);
	self = (LedBorgLedBorgClient*) g_object_new (object_type, NULL);
	_tmp0_ = host;
	led_borg_led_borg_client_set_server_host (self, _tmp0_);
	_tmp1_ = port;
	led_borg_led_borg_client_set_server_port (self, _tmp1_);
	return self;
}


LedBorgLedBorgClient* led_borg_led_borg_client_new (const gchar* host, guint port) {
	return led_borg_led_borg_client_construct (LED_BORG_TYPE_LED_BORG_CLIENT, host, port);
}


static gchar* led_borg_led_borg_client_generate_url (LedBorgLedBorgClient* self, const gchar* action, LedBorgColour* colour) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	guint _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* url;
	LedBorgColour* _tmp4_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (action != NULL, NULL);
	_tmp0_ = self->priv->_server_host;
	_tmp1_ = self->priv->_server_port;
	_tmp2_ = action;
	_tmp3_ = g_strdup_printf ("http://%s:%d/%s", _tmp0_, (gint) _tmp1_, _tmp2_);
	url = _tmp3_;
	_tmp4_ = colour;
	if (_tmp4_ != NULL) {
		const gchar* _tmp5_;
		const gchar* _tmp6_;
		LedBorgColour* _tmp7_;
		gint _tmp8_;
		LedBorgColour* _tmp9_;
		gint _tmp10_;
		LedBorgColour* _tmp11_;
		gint _tmp12_;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		gchar* _tmp15_;
		_tmp5_ = url;
		_tmp6_ = url;
		_tmp7_ = colour;
		_tmp8_ = (*_tmp7_).red;
		_tmp9_ = colour;
		_tmp10_ = (*_tmp9_).green;
		_tmp11_ = colour;
		_tmp12_ = (*_tmp11_).blue;
		_tmp13_ = g_strdup_printf (_tmp6_, "?red=%d&green=%d&blue=%d", _tmp8_, _tmp10_, _tmp12_);
		_tmp14_ = _tmp13_;
		_tmp15_ = g_strconcat (_tmp5_, _tmp14_, NULL);
		_g_free0 (url);
		url = _tmp15_;
		_g_free0 (_tmp14_);
	}
	result = url;
	return result;
}


void led_borg_led_borg_client_get_colour_from_server (LedBorgLedBorgClient* self, LedBorgColour* result, GError** error) {
	LedBorgColour colour = {0};
	gchar* _tmp0_ = NULL;
	gchar* url;
	const gchar* _tmp1_;
	SoupMessage* _tmp2_;
	SoupMessage* message;
	SoupSessionAsync* _tmp3_;
	SoupMessage* _tmp4_;
	guint _tmp5_ = 0U;
	guint status;
	guint _tmp6_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	memset (&colour, 0, sizeof (LedBorgColour));
	_tmp0_ = led_borg_led_borg_client_generate_url (self, "GetColour", NULL);
	url = _tmp0_;
	_tmp1_ = url;
	_tmp2_ = soup_message_new ("GET", _tmp1_);
	message = _tmp2_;
	_tmp3_ = self->priv->session;
	_tmp4_ = message;
	_tmp5_ = soup_session_send_message ((SoupSession*) _tmp3_, _tmp4_);
	status = _tmp5_;
	_tmp6_ = status;
	if (_tmp6_ == ((guint) SOUP_STATUS_OK)) {
		SoupMessage* _tmp7_;
		SoupMessageHeaders* _tmp8_;
		const gchar* _tmp9_ = NULL;
		_tmp7_ = message;
		_tmp8_ = _tmp7_->response_headers;
		_tmp9_ = soup_message_headers_get (_tmp8_, "Colour-LedBorg");
		led_borg_colour_init_with_rgb (&colour, _tmp9_);
	} else {
		const gchar* _tmp10_;
		guint _tmp11_;
		SoupMessage* _tmp12_;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		gchar* _tmp15_;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_;
		GError* _tmp18_;
		GError* _tmp19_;
		_tmp10_ = url;
		_tmp11_ = status;
		_tmp12_ = message;
		g_object_get (_tmp12_, "reason-phrase", &_tmp13_, NULL);
		_tmp14_ = _tmp13_;
		_tmp15_ = _tmp14_;
		_tmp16_ = g_strdup_printf ("Failed to communicate with server at %s - %d %s", _tmp10_, (gint) _tmp11_, _tmp15_);
		_tmp17_ = _tmp16_;
		_tmp18_ = g_error_new_literal (IO_ERROR, IO_ERROR_COMMUNICATION_BREAKDOWN, _tmp17_);
		_tmp19_ = _tmp18_;
		_g_free0 (_tmp17_);
		_g_free0 (_tmp15_);
		_inner_error_ = _tmp19_;
		if (_inner_error_->domain == IO_ERROR) {
			g_propagate_error (error, _inner_error_);
			_g_object_unref0 (message);
			_g_free0 (url);
			return;
		} else {
			_g_object_unref0 (message);
			_g_free0 (url);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	*result = colour;
	_g_object_unref0 (message);
	_g_free0 (url);
	return;
}


const gchar* led_borg_led_borg_client_get_server_host (LedBorgLedBorgClient* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_server_host;
	result = _tmp0_;
	return result;
}


void led_borg_led_borg_client_set_server_host (LedBorgLedBorgClient* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_server_host);
	self->priv->_server_host = _tmp1_;
	g_object_notify ((GObject *) self, "server-host");
}


guint led_borg_led_borg_client_get_server_port (LedBorgLedBorgClient* self) {
	guint result;
	guint _tmp0_;
	g_return_val_if_fail (self != NULL, 0U);
	_tmp0_ = self->priv->_server_port;
	result = _tmp0_;
	return result;
}


void led_borg_led_borg_client_set_server_port (LedBorgLedBorgClient* self, guint value) {
	guint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_server_port = _tmp0_;
	g_object_notify ((GObject *) self, "server-port");
}


static void led_borg_led_borg_client_class_init (LedBorgLedBorgClientClass * klass) {
	led_borg_led_borg_client_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (LedBorgLedBorgClientPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_led_borg_led_borg_client_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_led_borg_led_borg_client_set_property;
	G_OBJECT_CLASS (klass)->finalize = led_borg_led_borg_client_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), LED_BORG_LED_BORG_CLIENT_SERVER_HOST, g_param_spec_string ("server-host", "server-host", "server-host", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LED_BORG_LED_BORG_CLIENT_SERVER_PORT, g_param_spec_uint ("server-port", "server-port", "server-port", 0, G_MAXUINT, (guint) 9999, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void led_borg_led_borg_client_instance_init (LedBorgLedBorgClient * self) {
	SoupSessionAsync* _tmp0_;
	gchar* _tmp1_;
	self->priv = LED_BORG_LED_BORG_CLIENT_GET_PRIVATE (self);
	_tmp0_ = (SoupSessionAsync*) soup_session_async_new ();
	self->priv->session = _tmp0_;
	_tmp1_ = g_strdup ("127.0.0.1");
	self->priv->_server_host = _tmp1_;
	self->priv->_server_port = (guint) 9999;
}


static void led_borg_led_borg_client_finalize (GObject* obj) {
	LedBorgLedBorgClient * self;
	self = LED_BORG_LED_BORG_CLIENT (obj);
	_g_object_unref0 (self->priv->session);
	_g_free0 (self->priv->_server_host);
	G_OBJECT_CLASS (led_borg_led_borg_client_parent_class)->finalize (obj);
}


GType led_borg_led_borg_client_get_type (void) {
	static volatile gsize led_borg_led_borg_client_type_id__volatile = 0;
	if (g_once_init_enter (&led_borg_led_borg_client_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LedBorgLedBorgClientClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) led_borg_led_borg_client_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LedBorgLedBorgClient), 0, (GInstanceInitFunc) led_borg_led_borg_client_instance_init, NULL };
		GType led_borg_led_borg_client_type_id;
		led_borg_led_borg_client_type_id = g_type_register_static (G_TYPE_OBJECT, "LedBorgLedBorgClient", &g_define_type_info, 0);
		g_once_init_leave (&led_borg_led_borg_client_type_id__volatile, led_borg_led_borg_client_type_id);
	}
	return led_borg_led_borg_client_type_id__volatile;
}


static void _vala_led_borg_led_borg_client_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	LedBorgLedBorgClient * self;
	self = LED_BORG_LED_BORG_CLIENT (object);
	switch (property_id) {
		case LED_BORG_LED_BORG_CLIENT_SERVER_HOST:
		g_value_set_string (value, led_borg_led_borg_client_get_server_host (self));
		break;
		case LED_BORG_LED_BORG_CLIENT_SERVER_PORT:
		g_value_set_uint (value, led_borg_led_borg_client_get_server_port (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_led_borg_led_borg_client_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	LedBorgLedBorgClient * self;
	self = LED_BORG_LED_BORG_CLIENT (object);
	switch (property_id) {
		case LED_BORG_LED_BORG_CLIENT_SERVER_HOST:
		led_borg_led_borg_client_set_server_host (self, g_value_get_string (value));
		break;
		case LED_BORG_LED_BORG_CLIENT_SERVER_PORT:
		led_borg_led_borg_client_set_server_port (self, g_value_get_uint (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



