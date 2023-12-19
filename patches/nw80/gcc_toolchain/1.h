      soname_flag = ""
      if (current_os != "aix") {
        # -soname flag is not available on aix ld
        soname_flag = "-Wl,-soname=\"$soname\""
      }
      link_command = "$ld -shared $soname_flag {{ldflags}}${extra_ldflags} -o \"$unstripped_sofile\" @\"$rspfile\" {{rlibs}}"
//----replace
      soname_flag = ""
      start_group_flag = ""
      end_group_flag= ""
      if (current_os != "aix") {
        # -soname flag is not available on aix ld
        soname_flag = "-Wl,-soname=\"$soname\""
        start_group_flag = "-Wl,--start-group"
        end_group_flag = "-Wl,--end-group "
      }
      link_command = "$ld -shared $soname_flag {{ldflags}}${extra_ldflags} -o \"$unstripped_sofile\" @\"$rspfile\" $start_group_flag {{rlibs}} $end_group_flag"