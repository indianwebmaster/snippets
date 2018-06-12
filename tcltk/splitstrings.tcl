#!/usr/bin/env tclsh
set langs "Tcl,Java,C,C#,Ruby,Falcon"

puts [split $langs ,]
puts [join [split $langs ","] ":"]

set fields [split $langs ,]
puts $fields
puts "[lindex $fields 1]"
set field2 [lindex $fields 2]
puts $field2
