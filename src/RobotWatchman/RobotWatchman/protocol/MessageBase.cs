//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: MessageBase.proto
namespace Protocol
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"MessageBase")]
  public partial class MessageBase : global::ProtoBuf.IExtensible
  {
    public MessageBase() {}
    
    private uint _len;
    [global::ProtoBuf.ProtoMember(1, IsRequired = true, Name=@"len", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public uint len
    {
      get { return _len; }
      set { _len = value; }
    }
    private int _opcode;
    [global::ProtoBuf.ProtoMember(2, IsRequired = true, Name=@"opcode", DataFormat = global::ProtoBuf.DataFormat.TwosComplement)]
    public int opcode
    {
      get { return _opcode; }
      set { _opcode = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}