
        .arch       armv7e-m
        .cpu        cortex-m4

        .global     fix32_inv_table

        .type       fix32_inv_table,    "object"


@ The reciprocal lookup table. The table consist of 256 eight-bit entries.
@ Each entry represents the eight least significant bits of a nine-bit Q8
@ reciprocal of a number in the range from one-half to one. The ninth bit
@ is ignored since it is always set and can be restored by software. The
@ entries are packed into 32-bit little-endian words.

        .section   .fix32_inv_table
        .align

fix32_inv_table:
        .4byte      0xf9fbfdfe, 0xf1f3f5f7, 0xeaeceef0, 0xe3e5e6e8
        .4byte      0xdcdddfe1, 0xd5d7d8da, 0xced0d2d3, 0xc8c9cbcd
        .4byte      0xc2c3c5c6, 0xbcbdbfc0, 0xb6b7b9ba, 0xb0b1b3b4
        .4byte      0xaaacadae, 0xa5a6a7a9, 0x9fa1a2a3, 0x9a9c9d9e
        .4byte      0x95969899, 0x90919394, 0x8b8d8e8f, 0x8788898a
        .4byte      0x82838486, 0x7e7f8081, 0x797a7b7c, 0x75767778
        .4byte      0x71727374, 0x6d6e6f70, 0x696a6b6c, 0x65666768
        .4byte      0x61626364, 0x5d5e5f60, 0x595a5b5c, 0x56575858
        .4byte      0x52535455, 0x4f505151, 0x4b4c4d4e, 0x48494a4b
        .4byte      0x45464647, 0x42424344, 0x3f3f4041, 0x3b3c3d3e
        .4byte      0x38393a3b, 0x35363738, 0x33333435, 0x30303132
        .4byte      0x2d2e2e2f, 0x2a2b2c2c, 0x2828292a, 0x25262627
        .4byte      0x22232424, 0x20202122, 0x1d1e1e1f, 0x1b1b1c1d
        .4byte      0x18191a1a, 0x16171718, 0x14141515, 0x11121213
        .4byte      0x0f101011, 0x0d0d0e0f, 0x0b0b0c0c, 0x09090a0a
        .4byte      0x06070708, 0x04050506, 0x02030304, 0x00010102


        .end
