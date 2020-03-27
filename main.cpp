#include <iostream>
#include "DataStructures/SubsLinkedList.h"
#include "App/SubService.h"

/*
 * Ejemplo de patrón de diseño obsrever, se simula un servicio de subscripción que notifica cuando un artista sube nuevo
 * contenido a la página web
 * */

// Método main para probar el patrón de diseño

int main() {

    SubService Artist;      // La persona que crea contenido
    Artist.addSubscriber("Jose");       // Se añade un subscriptor
    Artist.addSubscriber("Fiorella");   // Se añade otro subscriptor

    Artist.setState("https:foo.com/content/Artist/adwkowpajdiawd1231a");    // La persona creadora sube el link para
    // que los subscriptores puedan verlo y los notifica de inmediato

    Artist.setState("https:foo.com/content/Artist/wewewewewe1234123132");

    Artist.addSubscriber("Maureen");    // Añade nuevos subscriptores
    Artist.addSubscriber("Ramón");

    Artist.setState("https:foo.com/content/Artist/uwuwuwuwuwu1234123132");
}
