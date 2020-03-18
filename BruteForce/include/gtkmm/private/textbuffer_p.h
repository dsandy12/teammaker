// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_TEXTBUFFER_P_H
#define _GTKMM_TEXTBUFFER_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class TextBuffer_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TextBuffer;
  using BaseObjectType = GtkTextBuffer;
  using BaseClassType = GtkTextBufferClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class TextBuffer;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void insert_text_callback(GtkTextBuffer* self, GtkTextIter* p0, const gchar* p1, gint p2);
  static void insert_pixbuf_callback(GtkTextBuffer* self, GtkTextIter* p0, GdkPixbuf* p1);
  static void insert_child_anchor_callback(GtkTextBuffer* self, GtkTextIter* p0, GtkTextChildAnchor* p1);
  static void delete_range_callback(GtkTextBuffer* self, GtkTextIter* p0, GtkTextIter* p1);
  static void changed_callback(GtkTextBuffer* self);
  static void modified_changed_callback(GtkTextBuffer* self);
  static void mark_set_callback(GtkTextBuffer* self, const GtkTextIter* p0, GtkTextMark* p1);
  static void mark_deleted_callback(GtkTextBuffer* self, GtkTextMark* p0);
  static void apply_tag_callback(GtkTextBuffer* self, GtkTextTag* p0, const GtkTextIter* p1, const GtkTextIter* p2);
  static void remove_tag_callback(GtkTextBuffer* self, GtkTextTag* p0, const GtkTextIter* p1, const GtkTextIter* p2);
  static void begin_user_action_callback(GtkTextBuffer* self);
  static void end_user_action_callback(GtkTextBuffer* self);
  static void paste_done_callback(GtkTextBuffer* self, GtkClipboard* p0);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_TEXTBUFFER_P_H */

