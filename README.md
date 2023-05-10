# Wiegenantrieb

Das Baby zum Schlafen bringen ist vermutlich eine Problemstellung, die so alt ist wie die Menschheit selbst ;-).

Hier ein kleines Tool, welches mit Ersatzteilen von einem alten 3D Drucker (NEMA17 Motor) und einem TMC2208 Treiber die Wiege antreibt. 
Dies ist ein erster Schuss! Weder mechanisch noch softwaremäßig ausgefeilt. Einfach etwas, das man abends mit schreiendem Baby auf dem Arm einhändig zusammenhackt. Jetzt schläft die Kleine, also ist der erste Versuch geglückt...


Hardware:
- Arduino UNO
- TMC2208 (Bigtreetech V3.0)
- NEMA17
- 12V Quelle

Software/Tooling:
- Arduino Framework (Framework super, IDE nicht so!)
- VSCode mit PlatformIO und den wunderbaren Plugins
- TMCStepper library (Versionsverwaltung über PlatformIO)
