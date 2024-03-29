// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_HANDLEBOX_P_H
#define _GTKMM_HANDLEBOX_P_H
#ifndef GTKMM_DISABLE_DEPRECATED


#include <gtkmm/private/bin_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class HandleBox_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = HandleBox;
  using BaseObjectType = GtkHandleBox;
  using BaseClassType = GtkHandleBoxClass;
  using CppClassParent = Gtk::Bin_Class;
  using BaseClassParent = GtkBinClass;

  friend class HandleBox;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void child_attached_callback(GtkHandleBox* self, GtkWidget* p0);
  static void child_detached_callback(GtkHandleBox* self, GtkWidget* p0);

  //Callbacks (virtual functions):
};


} // namespace Gtk

#endif // GTKMM_DISABLE_DEPRECATED


#endif /* _GTKMM_HANDLEBOX_P_H */

