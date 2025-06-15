package ejercicio05;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
import java.util.ArrayList;
// Autor: Chisus
// Fecha de creación: 05/06/2025

public class Test5 {

    public static void main(String[] args) {
        // Crear archivos
        Texto txt1 = new Texto(FormatoCodificacion.UTF_8, "Notas.txt", 15, "/documentos", true);
        Texto txt2 = new Texto(FormatoCodificacion.HEXADECIMAL, "Datos.txt", 20, "/descargas", false);

        Audio audio1 = new Audio("Artista1", "Album1", FormatoAudio.MP3, 180, "musica.mp3", 5000, "/musica", false);
        Audio audio2 = new Audio("Artista2", "Album2", FormatoAudio.WAV, 240, "cancion.wav", 8000, "/musica", true);

        Video video1 = new Video(new Pixeles(1920, 1080), FormatoVideo.MP4, 300, "pelicula.mp4", 15000, "/videos", true);
        Video video2 = new Video(new Pixeles(1280, 720), FormatoVideo.MKV, 600, "serie.mkv", 12000, "/series", false);

        // Crear lista de archivos
        ArrayList<Archivo> listaArchivos = new ArrayList<>();
        listaArchivos.add(txt1);
        listaArchivos.add(txt2);
        listaArchivos.add(audio1);
        listaArchivos.add(audio2);
        listaArchivos.add(video1);
        listaArchivos.add(video2);

        // Crear computadora
        Computadora pc = new Computadora("Lenovo ThinkPad", listaArchivos);

        // Test: cerrar todos
        pc.cerrarTodos();
        System.out.println("Todos los archivos han sido cerrados.");

        // Test: contar archivos de texto
        System.out.println("Cantidad de archivos de texto: " + pc.cantArchivosDeTexto());

        // Test: cifrar archivos UTF-8
        pc.cifrarArchivos();

        // Test: duración promedio
        System.out.println("Duración promedio de multimedia: " + pc.duracionPromedio() + " seg");

        // Test: videos FullHD
        ArrayList<Archivo> fullHD = pc.videosFullHD();
        System.out.println("Videos en Full HD:");
        for (Archivo a : fullHD) {
            System.out.println(a);
        }
    }
}
