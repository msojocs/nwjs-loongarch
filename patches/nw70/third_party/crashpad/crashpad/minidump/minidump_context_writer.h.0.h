  MinidumpContextMIPS64 context_;
};

}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_WRITER_H_

//----replace
  MinidumpContextMIPS64 context_;
};

//! \brief The writer for a MinidumpContextLOONGARCH64 structure in a minidump file.
class MinidumpContextLOONGARCH64Writer final : public MinidumpContextWriter {
 public:
  MinidumpContextLOONGARCH64Writer();
  ~MinidumpContextLOONGARCH64Writer() override;

  //! \brief Initializes the MinidumpContextLOONGARCH based on \a context_snapshot.
  //! 
  //! \param[in] context_snapshot The context snapshot to use as source data.
  //! 
  //! \note Valid in #kStateMutable. No mutation of context() may be done before
  //!     calling this method, and it is not normally necessary to alter
  //!     context() after calling this method.
  void InitializeFromSnapshot(const CPUContextLOONGARCH64* context_snapshot);

  //! \brief Returns a pointer to the context structure that this object will
  //!     write.
  //! 
  //! \attention This returns a non-`const` pointer to this object’s private
  //!     data so that a caller can populate the context structure directly.
  //!     This is done because providing setter interfaces to each field in the
  //!     context structure would be unwieldy and cumbersome. Care must be taken
  //!     to populate the context structure correctly. The context structure
  //!     must only be modified while this object is in the #kStateMutable
  //!     state.
  MinidumpContextLOONGARCH64* context() { return &context_; }

 protected:
  // MinidumpWritable:
  bool WriteObject(FileWriterInterface* file_writer) override;

  // MinidumpContextWriter:
  size_t ContextSize() const override;

 private:
  MinidumpContextLOONGARCH64 context_;
};


}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_WRITER_H_
