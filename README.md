

simple OSC
===
Simple library for sending and receiving OSC messages from Photon.

## What it does

- send floats
- send ints
- send string
- receive floats
- receive ints

## What it doesn't

- receive string
- receive blobs
- manage other OSC messages (booleans, timetags, bundles...)

#BEWARE

- If you try to send something different than floats and ints to the Photon, it will not work (you shouldn't be able to retrieve the datas.
- The following code isn't tested on particle1, any feedbacks are welcome.
- Another port of the osc library [exist]( https://github.com/trublion/sparkcore_osc).

--------------------------
[[Antoine M*]](ameisso.fr)