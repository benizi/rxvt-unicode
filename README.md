# 24bit (color)

This adds 24-bit color extensions to `rxvt-unicode`, mainly so I can use my
[custom version of Vim](https://github.com/benizi/vim) in a terminal, but with
GUI colorschemes.

# Very WIP

Based on the fact that almost every single one of my commits is prefixed with
`wip` (work in progress), you should probably not use this.  I've been using it
successfully since May, 2013 on a few machines.

# Added sequences:

- `SGR 38 ; 2 ; {r} ; {g} ; {b} ; m` - set foreground color
- `SGR 48 ; 2 ; {r} ; {g} ; {b} ; m` - set background color
- `SGR 38 ; 6 ; {r} ; {g} ; {b} ; m` - set default foreground color¹
- `SGR 48 ; 6 ; {r} ; {g} ; {b} ; m` - set default background color¹
- `SGR 38 ; 7 ; {r} ; {g} ; {b} ; m` - set cursor foreground color
- `SGR 48 ; 7 ; {r} ; {g} ; {b} ; m` - set cursor background color

E.g.:

`printf '\e[38;7;0;0;255m'` - set the cursor foreground to blue

¹: even more incomplete than the rest of this
