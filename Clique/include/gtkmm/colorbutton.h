// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_COLORBUTTON_H
#define _GTKMM_COLORBUTTON_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2003 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtkmm/button.h>
#include <gdkmm/color.h>
#include <gdkmm/rgba.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorButton = struct _GtkColorButton;
using GtkColorButtonClass = struct _GtkColorButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class ColorButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

//TODO: Derive from (and implement) ColorChooser when we can break ABI.

/** A button to launch a color selection dialog.
 *
 * The GtkColorButton is a button which displays the currently selected color an allows to
 * open a color selection dialog to change the color. It is suitable widget for selecting a
 * color in a preference dialog.
 *
 * The ColorButton widget looks like this:
 * @image html colorbutton1.png
 *
 * @ingroup Widgets
 */

class ColorButton : public Button
  //TODO: When we can break ABI: public ColorChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ColorButton CppObjectType;
  typedef ColorButton_Class CppClassType;
  typedef GtkColorButton BaseObjectType;
  typedef GtkColorButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ColorButton(ColorButton&& src) noexcept;
  ColorButton& operator=(ColorButton&& src) noexcept;

  // noncopyable
  ColorButton(const ColorButton&) = delete;
  ColorButton& operator=(const ColorButton&) = delete;

  ~ColorButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class ColorButton_Class;
  static CppClassType colorbutton_class_;

protected:
  explicit ColorButton(const Glib::ConstructParams& construct_params);
  explicit ColorButton(GtkColorButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkColorButton*       gobj()       { return reinterpret_cast<GtkColorButton*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkColorButton* gobj() const { return reinterpret_cast<GtkColorButton*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_color_set().
  virtual void on_color_set();


private:

  //TODO: When we can break ABI: _IMPLEMENTS_INTERFACE(ColorChooser)
public:

  /** Creates a new color button.
   *
   * This creates a widget in the form of a small button containing a swatch representing
   * the current selected color. When the button is clicked, a color-selection dialog will
   * open, allowing the user to select a color. The swatch will be updated to reflect the
   * new color when the user finishes.
   *
   * @newin{2,4}
   */
  ColorButton();
  

  // _WRAP_CTOR does not take a 'deprecated' parameter.
  // _WRAP_CTOR(ColorButton(const Gdk::Color& color), gtk_color_button_new_with_color)
#ifndef GTKMM_DISABLE_DEPRECATED
  /** Creates a new color button with a predefined color.
   *
   * Same as Gtk::ColorButton::ColorButton(). Additionally takes a Gdk::Color and
   * initializes the button with this color. Equivalent to calling set_color(@a color)
   * after the default constructor.
   *
   * @param color A Gdk::Color to set the current color with.
   *
   * @newin{2,4}
   * @deprecated "Use the constructor that takes a Gdk::RGBA instead."
   */
   explicit ColorButton(const Gdk::Color& color);
   
#endif //GTKMM_DISABLE_DEPRECATED

  /** Creates a new color button with a predefined color.
   *
   * Same as Gtk::ColorButton::ColorButton(). Additionally takes a Gdk::RGBA and
   * initializes the button with this color. Equivalent to calling set_rgba(@a color)
   * after the default constructor.
   *
   * @param rgba A Gdk::RGBA to set the current color with.
   *
   * @newin{3,0}
   */
    explicit ColorButton(const Gdk::RGBA& rgba);


  //TODO: When we can implement interface ColorChooser: deprecated "Use Gtk::ColorChooser::set_rgba() instead."
  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Sets the current color to be @a color.
   * 
   * @newin{2,4}
   * 
   * Deprecated: Use Gtk::ColorChooser::set_rgba() instead.
   * 
   * @deprecated Use set_rgba() instead.
   * 
   * @param color A Gdk::Color to set the current color with.
   */
  void set_color(const Gdk::Color& color);
#endif // GTKMM_DISABLE_DEPRECATED


  //TODO: When we can implement interface ColorChooser: deprecated "Use Gtk::ColorChooser::set_rgba() instead."
  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Sets the current opacity to be @a alpha.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Use Gtk::ColorChooser::set_rgba() instead.
   * 
   * @deprecated Use set_rgba() instead.
   * 
   * @param alpha An integer between 0 and 65535.
   */
  void set_alpha(guint16 alpha);
#endif // GTKMM_DISABLE_DEPRECATED


  //TODO: When we can implement interface ColorChooser: deprecated "Use Gtk::ColorChooser::set_rgba() instead."
  
  /** Sets the current color to be @a rgba.
   * 
   * @newin{3,0}
   * 
   * Deprecated: 3.4: Use Gtk::ColorChooser::set_rgba() instead.
   * 
   * @param rgba A Gdk::RGBA to set the current color with.
   */
  void set_rgba(const Gdk::RGBA& rgba);

#ifndef GTKMM_DISABLE_DEPRECATED

  //TODO: When we can implement interface ColorChooser: deprecated Use Gtk::ColorChooser::get_rgba() instead.
  /** Returns a copy of the the current color.
   *
   * Changes to the return value will have no effect on the Gtk::ColorButton.
   *
   * @return A Gdk::Color representing the current internal color of the Gtk::ColorButton.
   *
   * @newin{2,4}
   * @deprecated Use get_rgba() instead.
   */
  Gdk::Color get_color() const;
  

#endif //GTKMM_DISABLE_DEPRECATED

  //TODO: When we can implement interface ColorChooser: deprecated Use Gtk::ColorChooser::get_rgba() instead.
  /** Returns a copy of the the current color.
   *
   * Changes to the return value will have no effect on the Gtk::ColorButton.
   *
   * @return A Gdk::RGBA representing the current internal color of the Gtk::ColorButton.
   *
   * @newin{3,0}
   */
  Gdk::RGBA get_rgba() const;
  

  //TODO: When we can implement interface ColorChooser: deprecated "Use Gtk::ColorChooser::get_rgba() instead."
  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns the current alpha value.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Use Gtk::ColorChooser::get_rgba() instead.
   * 
   * @deprecated Use get_rgba() instead.
   * 
   * @return An integer between 0 and 65535.
   */
  guint16 get_alpha() const;
#endif // GTKMM_DISABLE_DEPRECATED


  //TODO: When we can implement interface ColorChooser: deprecated "Use Gtk::ColorChooser::set_use_alpha() instead."
  
  /** Sets whether or not the color button should use the alpha channel.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Use Gtk::ColorChooser::set_use_alpha() instead.
   * 
   * @param use_alpha <tt>true</tt> if color button should use alpha channel, <tt>false</tt> if not.
   */
  void set_use_alpha(bool use_alpha =  true);
  //TODO: When we can implement interface ColorChooser: deprecated "Use Gtk::ColorChooser::get_use_alpha() instead."
  
  /** Does the color selection dialog use the alpha channel ?
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Use Gtk::ColorChooser::get_use_alpha() instead.
   * 
   * @return <tt>true</tt> if the color sample uses alpha channel, <tt>false</tt> if not.
   */
  bool get_use_alpha() const;
  
  /** Sets the title for the color selection dialog.
   * 
   * @newin{2,4}
   * 
   * @param title String containing new window title.
   */
  void set_title(const Glib::ustring& title);
  
  /** Gets the title of the color selection dialog.
   * 
   * @newin{2,4}
   * 
   * @return The title.
   */
  Glib::ustring get_title() const;

  /** If this property is set to <tt>true</tt>, the color swatch on the button is
   * rendered against a checkerboard background to show its opacity and
   * the opacity slider is displayed in the color selection dialog.
   * 
   * @newin{2,4}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_use_alpha() ;

/** If this property is set to <tt>true</tt>, the color swatch on the button is
   * rendered against a checkerboard background to show its opacity and
   * the opacity slider is displayed in the color selection dialog.
   * 
   * @newin{2,4}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_use_alpha() const;

  /** The title of the color selection dialog
   * 
   * @newin{2,4}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_title() ;

/** The title of the color selection dialog
   * 
   * @newin{2,4}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_title() const;

  
#ifndef GTKMM_DISABLE_DEPRECATED

/** The selected color.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Use Gtk::ColorButton::property_rgba() instead.
   * 
   * @deprecated Use property_rgba() instead.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Gdk::Color > property_color() ;

/** The selected color.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Use Gtk::ColorButton::property_rgba() instead.
   * 
   * @deprecated Use property_rgba() instead.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gdk::Color > property_color() const;

#endif // GTKMM_DISABLE_DEPRECATED

  /** The RGBA color.
   * 
   * @newin{3,0}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Gdk::RGBA > property_rgba() ;

/** The RGBA color.
   * 
   * @newin{3,0}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gdk::RGBA > property_rgba() const;

  /** The selected opacity value (0 fully transparent, 65535 fully opaque).
   * 
   * @newin{2,4}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< guint16 > property_alpha() ;

/** The selected opacity value (0 fully transparent, 65535 fully opaque).
   * 
   * @newin{2,4}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< guint16 > property_alpha() const;
 //Todo: Remove this when we remove the "color" property too.
  /** Set this property to <tt>true</tt> to skip the palette
   * in the dialog and go directly to the color editor.
   * 
   * This property should be used in cases where the palette
   * in the editor would be redundant, such as when the color
   * button is already part of a palette.
   * 
   * @newin{3,20}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_show_editor() ;

/** Set this property to <tt>true</tt> to skip the palette
   * in the dialog and go directly to the color editor.
   * 
   * This property should be used in cases where the palette
   * in the editor would be redundant, such as when the color
   * button is already part of a palette.
   * 
   * @newin{3,20}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_show_editor() const;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%color_set()</tt>
   *
   * Flags: Run First
   *
   * The signal_color_set() signal is emitted when the user selects a color.
   * When handling this signal, use Gtk::ColorButton::get_rgba() to
   * find out which color was just selected.
   * 
   * Note that this signal is only emitted when the user
   * changes the color. If you need to react to programmatic color changes
   * as well, use the notify::color signal.
   * 
   * @newin{2,4}
   */

  Glib::SignalProxy< void > signal_color_set();


};


} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::ColorButton
   */
  Gtk::ColorButton* wrap(GtkColorButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_COLORBUTTON_H */

