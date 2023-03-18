local o = vim.o
local g = vim.g

-- color settings
o.termguicolors = false
o.background = 'dark'

-- decrease update time
o.timeoutlen = 500
o.updatetime = 200

-- better editor UI
o.number = true
o.relativenumber = false
o.cursorline = true

-- better editing experience
o.ttyfast = true
o.expandtab = true
o.tabstop = 4
o.softtabstop = 4
o.shiftwidth = 4
o.autoindent = true
o.cindent = false
o.list = true
o.listchars = 'trail:·,nbsp:◇,tab:→ ,extends:▸,precedes:◂'
o.hlsearch = true
o.incsearch = true

-- number of screen lines to keep above and below the cursor
o.scrolloff = 8

-- make nvim and system clipboard play nicely with each other
o.clipboard = 'unnamedplus'

-- case insensitive searching unless /C or capital in search
o.ignorecase = true
o.smartcase = true

-- undo and backup options
o.backup = false
o.writebackup = false
o.undofile = true
o.swapfile = false

-- remember 50 items in commandline history
o.history = 50

-- better buffer splitting
o.splitright = true
o.splitbelow = true

-- enable mouse
o.mouse = 'a'

-- map <leader> to space
g.mapleader = " "
g.maplocalleader = " "
