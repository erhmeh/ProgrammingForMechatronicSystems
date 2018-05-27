# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from lama_msgs/LamaObject.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class LamaObject(genpy.Message):
  _md5sum = "e2747a1741c10b06140b9673d9018102"
  _type = "lama_msgs/LamaObject"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# id of lama object in the database, will be unique.
# When adding a vertex into the database, this id will be ignored.
int32 id

# id of lama object in the world (usage is implementation specific).
int32 id_in_world

# name of object
string name

# emitter id and name.
int32 emitter_id
string emitter_name

# type: "EDGE" or "VERTEX"
int32 type
int32 VERTEX = 1
int32 EDGE = 2

# for edges: start and end vertices
# for vertices: not used
int32[2] references

"""
  # Pseudo-constants
  VERTEX = 1
  EDGE = 2

  __slots__ = ['id','id_in_world','name','emitter_id','emitter_name','type','references']
  _slot_types = ['int32','int32','string','int32','string','int32','int32[2]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       id,id_in_world,name,emitter_id,emitter_name,type,references

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LamaObject, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = 0
      if self.id_in_world is None:
        self.id_in_world = 0
      if self.name is None:
        self.name = ''
      if self.emitter_id is None:
        self.emitter_id = 0
      if self.emitter_name is None:
        self.emitter_name = ''
      if self.type is None:
        self.type = 0
      if self.references is None:
        self.references = [0] * 2
    else:
      self.id = 0
      self.id_in_world = 0
      self.name = ''
      self.emitter_id = 0
      self.emitter_name = ''
      self.type = 0
      self.references = [0] * 2

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2i().pack(_x.id, _x.id_in_world))
      _x = self.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_i().pack(self.emitter_id))
      _x = self.emitter_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_i().pack(self.type))
      buff.write(_get_struct_2i().pack(*self.references))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.id, _x.id_in_world,) = _get_struct_2i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.name = str[start:end].decode('utf-8')
      else:
        self.name = str[start:end]
      start = end
      end += 4
      (self.emitter_id,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.emitter_name = str[start:end].decode('utf-8')
      else:
        self.emitter_name = str[start:end]
      start = end
      end += 4
      (self.type,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 8
      self.references = _get_struct_2i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2i().pack(_x.id, _x.id_in_world))
      _x = self.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_i().pack(self.emitter_id))
      _x = self.emitter_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_i().pack(self.type))
      buff.write(self.references.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 8
      (_x.id, _x.id_in_world,) = _get_struct_2i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.name = str[start:end].decode('utf-8')
      else:
        self.name = str[start:end]
      start = end
      end += 4
      (self.emitter_id,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.emitter_name = str[start:end].decode('utf-8')
      else:
        self.emitter_name = str[start:end]
      start = end
      end += 4
      (self.type,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 8
      self.references = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=2)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
_struct_2i = None
def _get_struct_2i():
    global _struct_2i
    if _struct_2i is None:
        _struct_2i = struct.Struct("<2i")
    return _struct_2i
