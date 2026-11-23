# Vaja 1 – Prvi program na ESP32-C6

[Delovni list z navodili, primeri kode in vprašanji (DOCX)](Vaje_FM_01.docx) · [Arduino skica](vaje00/vaje00.ino)

Za 90-minutno vajo potrebujete ESP32-C6, podatkovni USB-kabel in računalnik z Arduino IDE ter Gitom.

1. V Arduino IDE izberite ploščico in vrata ter naložite program s števcem iz delovnega lista.
2. Odprite Serial Monitor pri 115200 baud. Opazujte, kako se izpis spremeni pri krajšem intervalu, pri uporabi `Serial.print()` namesto `Serial.println()` in po ponovnem zagonu ploščice. Če izpis prek vgrajenega USB ne deluje, preverite nastavitev **USB CDC On Boot** in po potrebi znova naložite skico.
3. Z uporabo `millis()` napišite program, ki vsako sekundo izpiše čas od zagona.
4. Shranite začetno različico programa in spremembo intervala v dveh Git commitih. Z ukazom `git log --oneline` preverite zgodovino.

Oddajte projektno mapo s skico `.ino`, odgovore na vprašanja iz delovnega lista in izpis zadnjih dveh commitov.
