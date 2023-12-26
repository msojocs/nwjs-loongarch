  MinidumpContextMIPS64 context_;
};

}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_WRITER_H_

//----replace
  MinidumpContextMIPS64 context_;
};

//! \brief The writer for a MinidumpContextLOONGARCH64 structure in a minidump file. // loongarch64
class MinidumpContextLOONGARCH64Writer final : public MinidumpContextWriter { // loongarch64
 public: // loongarch64
  MinidumpContextLOONGARCH64Writer(); // loongarch64
  ~MinidumpContextLOONGARCH64Writer() override; // loongarch64
 // loongarch64
  //! \brief Initializes the MinidumpContextLOONGARCH based on \a context_snapshot. // loongarch64
  //!  // loongarch64
  //! \param[in] context_snapshot The context snapshot to use as source data. // loongarch64
  //!  // loongarch64
  //! \note Valid in #kStateMutable. No mutation of context() may be done before // loongarch64
  //!     calling this method, and it is not normally necessary to alter // loongarch64
  //!     context() after calling this method. // loongarch64
  void InitializeFromSnapshot(const CPUContextLOONGARCH64* context_snapshot); // loongarch64
 // loongarch64
  //! \brief Returns a pointer to the context structure that this object will // loongarch64
  //!     write. // loongarch64
  //!  // loongarch64
  //! \attention This returns a non-`const` pointer to this object’s private // loongarch64
  //!     data so that a caller can populate the context structure directly. // loongarch64
  //!     This is done because providing setter interfaces to each field in the // loongarch64
  //!     context structure would be unwieldy and cumbersome. Care must be taken // loongarch64
  //!     to populate the context structure correctly. The context structure // loongarch64
  //!     must only be modified while this object is in the #kStateMutable // loongarch64
  //!     state. // loongarch64
  MinidumpContextLOONGARCH64* context() { return &context_; } // loongarch64
 // loongarch64
 protected: // loongarch64
  // MinidumpWritable: // loongarch64
  bool WriteObject(FileWriterInterface* file_writer) override; // loongarch64
 // loongarch64
  // MinidumpContextWriter: // loongarch64
  size_t ContextSize() const override; // loongarch64
 // loongarch64
 private: // loongarch64
  MinidumpContextLOONGARCH64 context_; // loongarch64
}; // loongarch64
 // loongarch64
 // loongarch64
}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_WRITER_H_
