# Infoscreen - Automatischer Bild-Slideshow-Player

Ein leichtgewichtiger, in C geschriebener **Infoscreen-Player**, der auf der [raylib](https://www.raylib.com/) Library basiert. Das Programm lädt automatisch alle Bilder aus einem Verzeichnis und spielt sie in einer Endlosschleife im Vollbildmodus ab.

## 🚀 Features

*   **Automatischer Import:** Scannt den Ordner `images/` beim Start nach `.png` und `.jpg` Dateien.
*   **Vollbildmodus:** Startet direkt im rahmenlosen Vollbild für professionelle Monitor-Anzeigen.
*   **Seitenverhältnis-Anpassung:** Nutzt `DrawTexturePro`, um Bilder auf die volle Bildschirmgröße zu skalieren.
*   **Timer-Steuerung:** Die Anzeigedauer pro Bild ist im Code leicht anpassbar (standardmäßig 10 Sekunden).
*   **Ressourcenschonend:** Nutzt die GPU-Beschleunigung über raylib für flüssige Darstellung bei minimaler CPU-Last.

---

## 🛠 Voraussetzungen

Bevor du das Projekt kompilieren kannst, müssen folgende Komponenten installiert sein:

1.  **C-Compiler:** GCC (MinGW für Windows, Clang für macOS oder GCC für Linux).
2.  **raylib:** Die raylib Entwicklungs-Header und Bibliotheken.
3.  **Make (optional):** Zum einfachen Bauen über das bereitgestellte Makefile.
4.  **Ordnerstruktur:** Erstelle einen Ordner namens `images` im selben Verzeichnis wie die ausführbare Datei und fülle ihn mit deinen Medien.

---

## 📦 Installation & Kompilierung

### 1. Repository klonen
```bash
git clone https://github.com/derfabiannn/infoscreen.git
cd infoscreen
```

### 2. Bilder vorbereiten
Stelle sicher, dass deine Verzeichnisstruktur wie folgt aussieht:
```text
.
├── main.c           # Der Quellcode
├── Makefile         # Automatisierungstool für den Build
└── images/          # Dein Ordner mit Bildern (.jpg, .png)
    ├── bild1.jpg
    └── bild2.png
```

### 3. Bauen (Kompilieren)

Du kannst das Projekt auf zwei Arten bauen:

#### **Variante A: Mit Make (Empfohlen)**
Falls `make` auf deinem System installiert ist, reicht ein einziger Befehl im Terminal:
```bash
make
```
*Das Makefile übernimmt automatisch das Verknüpfen aller notwendigen Bibliotheken (raylib, OpenGL, etc.).*

#### **Variante B: Manueller Build (GCC)**
Falls du kein `make` nutzt, verwende den entsprechenden Befehl für dein Betriebssystem:

**Windows (MinGW):**
```bash
gcc main.c -o infoscreen.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

**Linux:**
```bash
gcc main.c -o infoscreen -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

---

## 🎮 Benutzung

Starte die Anwendung nach dem Kompilieren einfach per Doppelklick oder über das Terminal:
```bash
./infoscreen
```

*   **Beenden:** Drücke die Taste `ESC`, um das Programm sicher zu schließen.
*   **Dauer ändern:** Ändere den Wert der Variable `displayDuration` in der `main.c`, um die Zeit pro Bild anzupassen.
*   **Aufräumen:** Mit `make clean` kannst du die erstellte ausführbare Datei wieder löschen.

---

## ⚙️ Technische Details

*   **MAX_IMAGES:** Die Anzahl der Bilder ist im Quellcode auf 100 begrenzt (einfach über `#define` änderbar).
*   **Skalierung:** Das Programm nutzt die GPU, um Bilder in Echtzeit auf die native Bildschirmauflösung zu skalieren.
*   **Speichermanagement:** Um Memory Leaks zu vermeiden, werden alle Texturen beim Beenden via `UnloadTexture()` sauber aus dem VRAM entfernt.

---

## 📄 Lizenz

Dieses Projekt ist unter der MIT-Lizenz lizenziert.

*Erstellt mit ❤️ und [raylib](https://www.raylib.com/)*

> **Hinweis:** Diese README wurde KI-generiert und von einem Menschen überarbeitet, um technische Korrektheit und Klarheit zu gewährleisten.
