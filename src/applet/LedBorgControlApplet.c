/* LedBorgControlApplet.c generated by valac 0.16.1, the Vala compiler
 * generated from LedBorgControlApplet.vala, do not modify */

/*
 * LedBorgControlApplet.vala
 * This file is part of LedBorg-Control-Applet
 *
 * Copyright (C) 2013 - Ross Taylor
 *
 * LedBorg-Control-Applet is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * LedBorg-Control-Applet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LedBorg-Control-Applet. If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <float.h>
#include <math.h>
#include <cairo.h>
#include <gdk-pixbuf/gdk-pixbuf.h>


#define LED_BORG_TYPE_LED_BORG_CONTROL_APPLET (led_borg_led_borg_control_applet_get_type ())
#define LED_BORG_LED_BORG_CONTROL_APPLET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LED_BORG_TYPE_LED_BORG_CONTROL_APPLET, LedBorgLedBorgControlApplet))
#define LED_BORG_LED_BORG_CONTROL_APPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LED_BORG_TYPE_LED_BORG_CONTROL_APPLET, LedBorgLedBorgControlAppletClass))
#define LED_BORG_IS_LED_BORG_CONTROL_APPLET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LED_BORG_TYPE_LED_BORG_CONTROL_APPLET))
#define LED_BORG_IS_LED_BORG_CONTROL_APPLET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LED_BORG_TYPE_LED_BORG_CONTROL_APPLET))
#define LED_BORG_LED_BORG_CONTROL_APPLET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LED_BORG_TYPE_LED_BORG_CONTROL_APPLET, LedBorgLedBorgControlAppletClass))

typedef struct _LedBorgLedBorgControlApplet LedBorgLedBorgControlApplet;
typedef struct _LedBorgLedBorgControlAppletClass LedBorgLedBorgControlAppletClass;
typedef struct _LedBorgLedBorgControlAppletPrivate LedBorgLedBorgControlAppletPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define LED_BORG_TYPE_LED_BORG_CLIENT (led_borg_led_borg_client_get_type ())
#define LED_BORG_LED_BORG_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LED_BORG_TYPE_LED_BORG_CLIENT, LedBorgLedBorgClient))
#define LED_BORG_LED_BORG_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LED_BORG_TYPE_LED_BORG_CLIENT, LedBorgLedBorgClientClass))
#define LED_BORG_IS_LED_BORG_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LED_BORG_TYPE_LED_BORG_CLIENT))
#define LED_BORG_IS_LED_BORG_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LED_BORG_TYPE_LED_BORG_CLIENT))
#define LED_BORG_LED_BORG_CLIENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LED_BORG_TYPE_LED_BORG_CLIENT, LedBorgLedBorgClientClass))

typedef struct _LedBorgLedBorgClient LedBorgLedBorgClient;
typedef struct _LedBorgLedBorgClientClass LedBorgLedBorgClientClass;

#define LED_BORG_TYPE_COLOUR (led_borg_colour_get_type ())
typedef struct _LedBorgColour LedBorgColour;
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))

struct _LedBorgLedBorgControlApplet {
	GObject parent_instance;
	LedBorgLedBorgControlAppletPrivate * priv;
};

struct _LedBorgLedBorgControlAppletClass {
	GObjectClass parent_class;
};

struct _LedBorgLedBorgControlAppletPrivate {
	gchar* _server_host;
	guint _server_port;
	GtkStatusIcon* trayicon;
	gint old_size;
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

static gpointer led_borg_led_borg_control_applet_parent_class = NULL;

GType led_borg_led_borg_control_applet_get_type (void) G_GNUC_CONST;
#define LED_BORG_LED_BORG_CONTROL_APPLET_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), LED_BORG_TYPE_LED_BORG_CONTROL_APPLET, LedBorgLedBorgControlAppletPrivate))
enum  {
	LED_BORG_LED_BORG_CONTROL_APPLET_DUMMY_PROPERTY,
	LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_HOST,
	LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_PORT
};
LedBorgLedBorgControlApplet* led_borg_led_borg_control_applet_new (const gchar* host, guint port);
LedBorgLedBorgControlApplet* led_borg_led_borg_control_applet_construct (GType object_type, const gchar* host, guint port);
void led_borg_led_borg_control_applet_set_server_host (LedBorgLedBorgControlApplet* self, const gchar* value);
void led_borg_led_borg_control_applet_set_server_port (LedBorgLedBorgControlApplet* self, guint value);
gboolean led_borg_led_borg_control_applet_repaint (LedBorgLedBorgControlApplet* self);
static gboolean _led_borg_led_borg_control_applet_repaint_gtk_status_icon_size_changed (GtkStatusIcon* _sender, gint size, gpointer self);
void led_borg_led_borg_control_applet_PixbufDestroyNotify (LedBorgLedBorgControlApplet* self, guint8* pixels);
gboolean led_borg_led_borg_control_applet_timer (LedBorgLedBorgControlApplet* self);
const gchar* led_borg_led_borg_control_applet_get_server_host (LedBorgLedBorgControlApplet* self);
guint led_borg_led_borg_control_applet_get_server_port (LedBorgLedBorgControlApplet* self);
LedBorgLedBorgClient* led_borg_led_borg_client_new (const gchar* host, guint port);
LedBorgLedBorgClient* led_borg_led_borg_client_construct (GType object_type, const gchar* host, guint port);
GType led_borg_led_borg_client_get_type (void) G_GNUC_CONST;
GType led_borg_colour_get_type (void) G_GNUC_CONST;
LedBorgColour* led_borg_colour_dup (const LedBorgColour* self);
void led_borg_colour_free (LedBorgColour* self);
GQuark io_error_quark (void);
void led_borg_led_borg_client_get_colour_from_server (LedBorgLedBorgClient* self, LedBorgColour* result, GError** error);
gchar* led_borg_colour_to_string (LedBorgColour *self);
static void _led_borg_led_borg_control_applet_PixbufDestroyNotify_gdk_pixbuf_destroy_notify (guint8* pixels, gpointer self);
static gboolean _led_borg_led_borg_control_applet_timer_gsource_func (gpointer self);
static void led_borg_led_borg_control_applet_finalize (GObject* obj);
static void _vala_led_borg_led_borg_control_applet_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_led_borg_led_borg_control_applet_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gboolean _led_borg_led_borg_control_applet_repaint_gtk_status_icon_size_changed (GtkStatusIcon* _sender, gint size, gpointer self) {
	gboolean result;
	result = led_borg_led_borg_control_applet_repaint (self);
	return result;
}


LedBorgLedBorgControlApplet* led_borg_led_borg_control_applet_construct (GType object_type, const gchar* host, guint port) {
	LedBorgLedBorgControlApplet * self = NULL;
	const gchar* _tmp0_;
	guint _tmp1_;
	GtkStatusIcon* _tmp2_;
	GtkStatusIcon* _tmp3_;
	GtkStatusIcon* _tmp4_;
	GtkStatusIcon* _tmp5_;
	GtkStatusIcon* _tmp6_;
	g_return_val_if_fail (host != NULL, NULL);
	self = (LedBorgLedBorgControlApplet*) g_object_new (object_type, NULL);
	_tmp0_ = host;
	led_borg_led_borg_control_applet_set_server_host (self, _tmp0_);
	_tmp1_ = port;
	led_borg_led_borg_control_applet_set_server_port (self, _tmp1_);
	_tmp2_ = gtk_status_icon_new ();
	_g_object_unref0 (self->priv->trayicon);
	self->priv->trayicon = _tmp2_;
	_tmp3_ = self->priv->trayicon;
	gtk_status_icon_set_visible (_tmp3_, TRUE);
	_tmp4_ = self->priv->trayicon;
	gtk_status_icon_set_name (_tmp4_, "LedBorg Control Applet");
	_tmp5_ = self->priv->trayicon;
	gtk_status_icon_set_title (_tmp5_, "LedBorg Control Applet");
	_tmp6_ = self->priv->trayicon;
	g_signal_connect_object (_tmp6_, "size-changed", (GCallback) _led_borg_led_borg_control_applet_repaint_gtk_status_icon_size_changed, self, 0);
	return self;
}


LedBorgLedBorgControlApplet* led_borg_led_borg_control_applet_new (const gchar* host, guint port) {
	return led_borg_led_borg_control_applet_construct (LED_BORG_TYPE_LED_BORG_CONTROL_APPLET, host, port);
}


void led_borg_led_borg_control_applet_PixbufDestroyNotify (LedBorgLedBorgControlApplet* self, guint8* pixels) {
	guint8* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = pixels;
	g_free (_tmp0_);
}


gboolean led_borg_led_borg_control_applet_timer (LedBorgLedBorgControlApplet* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	led_borg_led_borg_control_applet_repaint (self);
	result = FALSE;
	return result;
}


static void _led_borg_led_borg_control_applet_PixbufDestroyNotify_gdk_pixbuf_destroy_notify (guint8* pixels, gpointer self) {
	led_borg_led_borg_control_applet_PixbufDestroyNotify (self, pixels);
}


static gboolean _led_borg_led_borg_control_applet_timer_gsource_func (gpointer self) {
	gboolean result;
	result = led_borg_led_borg_control_applet_timer (self);
	return result;
}


gboolean led_borg_led_borg_control_applet_repaint (LedBorgLedBorgControlApplet* self) {
	gboolean result = FALSE;
	GtkStatusIcon* _tmp0_;
	gint _tmp1_ = 0;
	gint size;
	gdouble red;
	gdouble green;
	gdouble blue;
	const gchar* _tmp2_;
	guint _tmp3_;
	LedBorgLedBorgClient* _tmp4_;
	LedBorgLedBorgClient* client;
	LedBorgColour _tmp5_ = {0};
	LedBorgColour colour;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_;
	gboolean _tmp8_;
	cairo_surface_t* _tmp15_;
	cairo_surface_t* canvas;
	cairo_surface_t* _tmp16_;
	cairo_t* _tmp17_;
	cairo_t* ctx;
	cairo_t* _tmp18_;
	cairo_t* _tmp19_;
	cairo_t* _tmp20_;
	cairo_t* _tmp21_;
	cairo_t* _tmp22_;
	cairo_t* _tmp23_;
	gdouble _tmp24_;
	gdouble _tmp25_;
	gdouble _tmp26_;
	cairo_t* _tmp27_;
	cairo_t* _tmp28_;
	guint8* _tmp29_ = NULL;
	guint8* pixel_data;
	guint8* _tmp30_;
	GdkPixbuf* _tmp31_;
	GdkPixbuf* pix;
	guint8* _tmp32_;
	guint8* p1;
	cairo_surface_t* _tmp33_;
	guchar* _tmp34_ = NULL;
	guint8* p2;
	gint counter = 0;
	gint max;
	GtkStatusIcon* _tmp54_;
	GdkPixbuf* _tmp55_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->trayicon;
	_tmp1_ = gtk_status_icon_get_size (_tmp0_);
	size = _tmp1_;
	red = (gdouble) 0;
	green = (gdouble) 0;
	blue = (gdouble) 0;
	_tmp2_ = self->priv->_server_host;
	_tmp3_ = self->priv->_server_port;
	_tmp4_ = led_borg_led_borg_client_new (_tmp2_, _tmp3_);
	client = _tmp4_;
	led_borg_led_borg_client_get_colour_from_server (client, &_tmp5_, &_inner_error_);
	colour = _tmp5_;
	if (_inner_error_ != NULL) {
		_g_object_unref0 (client);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	_tmp6_ = led_borg_colour_to_string (&colour);
	_tmp7_ = _tmp6_;
	_tmp8_ = g_strcmp0 (_tmp7_, "") != 0;
	_g_free0 (_tmp7_);
	if (_tmp8_) {
		LedBorgColour _tmp9_;
		gint _tmp10_;
		LedBorgColour _tmp11_;
		gint _tmp12_;
		LedBorgColour _tmp13_;
		gint _tmp14_;
		_tmp9_ = colour;
		_tmp10_ = _tmp9_.red;
		red = ((gdouble) _tmp10_) / 2;
		_tmp11_ = colour;
		_tmp12_ = _tmp11_.green;
		green = ((gdouble) _tmp12_) / 2;
		_tmp13_ = colour;
		_tmp14_ = _tmp13_.blue;
		blue = ((gdouble) _tmp14_) / 2;
	}
	_tmp15_ = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, size, size);
	canvas = _tmp15_;
	_tmp16_ = canvas;
	_tmp17_ = cairo_create (_tmp16_);
	ctx = _tmp17_;
	_tmp18_ = ctx;
	cairo_scale (_tmp18_, (gdouble) size, (gdouble) size);
	_tmp19_ = ctx;
	cairo_set_source_rgb (_tmp19_, (gdouble) 0, (gdouble) 0, (gdouble) 0);
	_tmp20_ = ctx;
	cairo_rectangle (_tmp20_, (gdouble) 0, (gdouble) 0, (gdouble) 1, 0.5);
	_tmp21_ = ctx;
	cairo_set_line_width (_tmp21_, 0.2);
	_tmp22_ = ctx;
	cairo_stroke (_tmp22_);
	_tmp23_ = ctx;
	_tmp24_ = red;
	_tmp25_ = green;
	_tmp26_ = blue;
	cairo_set_source_rgb (_tmp23_, _tmp24_, _tmp25_, _tmp26_);
	_tmp27_ = ctx;
	cairo_in_fill (_tmp27_, 0.5, 0.25);
	_tmp28_ = ctx;
	cairo_paint (_tmp28_);
	_tmp29_ = g_new0 (guint8, (size * size) * 4);
	pixel_data = _tmp29_;
	_tmp30_ = pixel_data;
	_tmp31_ = gdk_pixbuf_new_from_data ((guint8*) _tmp30_, GDK_COLORSPACE_RGB, TRUE, 8, size, size, size * 4, _led_borg_led_borg_control_applet_PixbufDestroyNotify_gdk_pixbuf_destroy_notify, self);
	pix = _tmp31_;
	_tmp32_ = pixel_data;
	p1 = _tmp32_;
	_tmp33_ = canvas;
	_tmp34_ = cairo_image_surface_get_data (_tmp33_);
	p2 = _tmp34_;
	max = size * size;
	{
		gboolean _tmp35_;
		counter = 0;
		_tmp35_ = TRUE;
		while (TRUE) {
			gboolean _tmp36_;
			gint _tmp38_;
			gint _tmp39_;
			guint8* _tmp40_;
			guint8* _tmp41_;
			guint8 _tmp42_;
			guint8* _tmp43_;
			guint8* _tmp44_;
			guint8 _tmp45_;
			guint8* _tmp46_;
			guint8* _tmp47_;
			guint8 _tmp48_;
			guint8* _tmp49_;
			guint8* _tmp50_;
			guint8 _tmp51_;
			guint8* _tmp52_;
			guint8* _tmp53_;
			_tmp36_ = _tmp35_;
			if (!_tmp36_) {
				gint _tmp37_;
				_tmp37_ = counter;
				counter = _tmp37_ + 1;
			}
			_tmp35_ = FALSE;
			_tmp38_ = counter;
			_tmp39_ = max;
			if (!(_tmp38_ < _tmp39_)) {
				break;
			}
			_tmp40_ = p1;
			_tmp41_ = p2;
			*_tmp40_ = *(_tmp41_ + 2);
			_tmp42_ = *_tmp40_;
			_tmp43_ = p1;
			_tmp44_ = p2;
			*(_tmp43_ + 1) = *(_tmp44_ + 1);
			_tmp45_ = *(_tmp43_ + 1);
			_tmp46_ = p1;
			_tmp47_ = p2;
			*(_tmp46_ + 2) = *_tmp47_;
			_tmp48_ = *(_tmp46_ + 2);
			_tmp49_ = p1;
			_tmp50_ = p2;
			*(_tmp49_ + 3) = *(_tmp50_ + 3);
			_tmp51_ = *(_tmp49_ + 3);
			_tmp52_ = p1;
			p1 = _tmp52_ + 4;
			_tmp53_ = p2;
			p2 = _tmp53_ + 4;
		}
	}
	_tmp54_ = self->priv->trayicon;
	_tmp55_ = pix;
	gtk_status_icon_set_from_pixbuf (_tmp54_, _tmp55_);
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 1000, _led_borg_led_borg_control_applet_timer_gsource_func, g_object_ref (self), g_object_unref);
	result = TRUE;
	_g_object_unref0 (pix);
	_cairo_destroy0 (ctx);
	_cairo_surface_destroy0 (canvas);
	_g_object_unref0 (client);
	return result;
}


const gchar* led_borg_led_borg_control_applet_get_server_host (LedBorgLedBorgControlApplet* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_server_host;
	result = _tmp0_;
	return result;
}


void led_borg_led_borg_control_applet_set_server_host (LedBorgLedBorgControlApplet* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_server_host);
	self->priv->_server_host = _tmp1_;
	g_object_notify ((GObject *) self, "server-host");
}


guint led_borg_led_borg_control_applet_get_server_port (LedBorgLedBorgControlApplet* self) {
	guint result;
	guint _tmp0_;
	g_return_val_if_fail (self != NULL, 0U);
	_tmp0_ = self->priv->_server_port;
	result = _tmp0_;
	return result;
}


void led_borg_led_borg_control_applet_set_server_port (LedBorgLedBorgControlApplet* self, guint value) {
	guint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_server_port = _tmp0_;
	g_object_notify ((GObject *) self, "server-port");
}


static void led_borg_led_borg_control_applet_class_init (LedBorgLedBorgControlAppletClass * klass) {
	led_borg_led_borg_control_applet_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (LedBorgLedBorgControlAppletPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_led_borg_led_borg_control_applet_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_led_borg_led_borg_control_applet_set_property;
	G_OBJECT_CLASS (klass)->finalize = led_borg_led_borg_control_applet_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_HOST, g_param_spec_string ("server-host", "server-host", "server-host", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_PORT, g_param_spec_uint ("server-port", "server-port", "server-port", 0, G_MAXUINT, 0U, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void led_borg_led_borg_control_applet_instance_init (LedBorgLedBorgControlApplet * self) {
	self->priv = LED_BORG_LED_BORG_CONTROL_APPLET_GET_PRIVATE (self);
}


static void led_borg_led_borg_control_applet_finalize (GObject* obj) {
	LedBorgLedBorgControlApplet * self;
	self = LED_BORG_LED_BORG_CONTROL_APPLET (obj);
	_g_free0 (self->priv->_server_host);
	_g_object_unref0 (self->priv->trayicon);
	G_OBJECT_CLASS (led_borg_led_borg_control_applet_parent_class)->finalize (obj);
}


GType led_borg_led_borg_control_applet_get_type (void) {
	static volatile gsize led_borg_led_borg_control_applet_type_id__volatile = 0;
	if (g_once_init_enter (&led_borg_led_borg_control_applet_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LedBorgLedBorgControlAppletClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) led_borg_led_borg_control_applet_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LedBorgLedBorgControlApplet), 0, (GInstanceInitFunc) led_borg_led_borg_control_applet_instance_init, NULL };
		GType led_borg_led_borg_control_applet_type_id;
		led_borg_led_borg_control_applet_type_id = g_type_register_static (G_TYPE_OBJECT, "LedBorgLedBorgControlApplet", &g_define_type_info, 0);
		g_once_init_leave (&led_borg_led_borg_control_applet_type_id__volatile, led_borg_led_borg_control_applet_type_id);
	}
	return led_borg_led_borg_control_applet_type_id__volatile;
}


static void _vala_led_borg_led_borg_control_applet_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	LedBorgLedBorgControlApplet * self;
	self = LED_BORG_LED_BORG_CONTROL_APPLET (object);
	switch (property_id) {
		case LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_HOST:
		g_value_set_string (value, led_borg_led_borg_control_applet_get_server_host (self));
		break;
		case LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_PORT:
		g_value_set_uint (value, led_borg_led_borg_control_applet_get_server_port (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_led_borg_led_borg_control_applet_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	LedBorgLedBorgControlApplet * self;
	self = LED_BORG_LED_BORG_CONTROL_APPLET (object);
	switch (property_id) {
		case LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_HOST:
		led_borg_led_borg_control_applet_set_server_host (self, g_value_get_string (value));
		break;
		case LED_BORG_LED_BORG_CONTROL_APPLET_SERVER_PORT:
		led_borg_led_borg_control_applet_set_server_port (self, g_value_get_uint (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



