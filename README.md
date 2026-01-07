# TabulaOS

> **"Tabula Rasa" (Latin): A clean slate.**

**TabulaOS** is a hyper-minimal Linux distribution designed specifically for students and academics. It provides a distraction-free environment that comes empty by default, allowing the user to "curate" their own operating system during installation.

Unlike standard distributions that come pre-loaded with bloatware, games, and unnecessary services, TabulaOS respects your focus. It boots into a custom-built, lightweight C interface where you select only the tools you need for your specific field of study—be it Computer Science, Literature, or Mathematics.

## 🎯 Project Philosophy

* **Intentional Minimalism:** If you don't use it, it shouldn't be installed.
* **Student-Centric:** Curated categories for Coding, Writing, and Research tools.
* **Lightweight:** Runs on a minimal Window Manager (Openbox/i3), making it perfect for older student laptops or maximizing battery life.
* **Transparent:** The installer is a simple, compiled C program. No hidden telemetry, no heavy GUI installers.

## 🛠️ The Tech Stack

* **Base System:** Minimal Linux (Arch-based).
* **Installer:** `tabula-installer` — A custom TUI (Text User Interface) written in **C** using `ncurses`.
* **Window Manager:** Openbox (Planned).

## 🚀 The Tabula Selector

The heart of this distribution is the custom installer written in C. It replaces complex graphical wizards with a lightning-fast terminal interface.

### Preview
The installer allows users to toggle selection using `SPACE` and install via `ENTER`.

```text
  Welcome to TabulaOS Setup
  Use UP/DOWN to move, SPACE to select, ENTER to install.

  [x] Visual Studio Code
  [ ] LibreOffice
  [x] Obsidian (Notes)
  [ ] Spotify
  [ ] GIMP (Image Editor)