      link_command = "$ld {{ldflags}}${extra_ldflags} -o \"$unstripped_outfile\" $start_group_flag @\"$rspfile\" {{solibs}} $end_group_flag {{libs}} {{rlibs}}"
//----replace
      link_command = "$ld {{ldflags}}${extra_ldflags} -o \"$unstripped_outfile\" $start_group_flag @\"$rspfile\" {{solibs}} {{rlibs}} $end_group_flag {{libs}}"