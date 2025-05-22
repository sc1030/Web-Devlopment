console.log('Lets write JavaScript');
// let currentSong = new Audio();
let songs;
let currFolder;


function secondsToMinutesSeconds(seconds) {
    if (isNaN(seconds) || seconds < 0) {
        return "00:00";
    }

    const minutes = Math.floor(seconds / 60);
    const remainingSeconds = Math.floor(seconds % 60);

    const formattedMinutes = String(minutes).padStart(2, '0');
    const formattedSeconds = String(remainingSeconds).padStart(2, '0');

    return `${formattedMinutes}:${formattedSeconds}`;
}
async function getSongs(folder) {
    try {
        let response = await fetch("http://127.0.0.1:5500/songs/");
        let data = await response.text();
        console.log(data);
        let div = document.createElement("div");
        div.innerHTML = data;
        let as = div.getElementsByTagName("a");
        let songs = [];

        for (let index = 0; index < as.length; index++) {
            const element = as[index];
            if (element.href.endsWith(".mp3")) {
                songs.push(element.href.split("/songs/")[1]); // Get the second part
            }
        }
        console.log(songs);
        return songs;
    } catch (error) {
        console.error("Error fetching songs:", error);
        throw error; // Re-throw the error to be caught in the main function
    }
}

const playMusic = (track, pause=false) => {
    currentSong.src = "/songs/" + track
    if(!pause){
        currentSong.play()
    play.src = "pause.svg"
    }
    
    document.querySelector(".songinfo").innerHTML = track
    document.querySelector(".songtime").innerHTML = "00:00 / 00:00"
}




async function main() {
    try {
        let songs = await getSongs();
        console.log(songs[0], true);

        let songUL = document.querySelector(".songList").getElementsByTagName("ul")[0];

        for (const song of songs) {
            songUL.innerHTML = songUL.innerHTML + `<li><img class="invert" width="34" src="img/music.svg" alt="">
            <div class="info">
                <div> ${song.replaceAll("%20", " ")}</div>
                <div>Harry</div>
            </div>
            <div class="playnow">
                <span>Play Now</span>
                <img class="invert" src="img/play.svg" alt="">
            </div> </li>`;
        }

        // Attach an event listener to each song
    Array.from(document.querySelector(".songList").getElementsByTagName("li")).forEach(e => {
        e.addEventListener("click", element => {
            console.log(e.querySelector(".info").firstElementChild.innerHTML)
            playMusic(e.querySelector(".info").firstElementChild.innerHTML.trim())

        })
    })

    return songs


        var audio = new Audio(songs[0]); // Assuming you want to play the first song
        audio.play();

        audio.addEventListener("loadeddata", () => {
            let duration = audio.duration;
            console.log(duration);
        });
    }catch (error) {
        // console.error("Error in main function:", error);
    }
}

const currentSong = new Audio();
play.addEventListener("click", () => {
    if(currentSong.paused){
        currentSong.play();
        play.src = "paused.svg"
    }
    else{
        currentSong.paused();
        paused.src = "play.svg"
    }
});   


// Assuming you have a function secondsToMinutesSeconds defined elsewhere in your code

currentSong.addEventListener("timeupdate", () => {
    document.querySelector(".songtime").innerHTML = `${secondsToMinutesSeconds(currentSong.currentTime)} / ${secondsToMinutesSeconds(currentSong.duration)}`
    document.querySelector(".circle").style.left = (currentSong.currentTime / currentSong.duration) * 100 + "%";
})

 // Add an event listener to seekbar
 document.querySelector(".seekbar").addEventListener("click", e => {
    let percent = (e.offsetX / e.target.getBoundingClientRect().width) * 100;
    document.querySelector(".circle").style.left = percent + "%";
    currentSong.currentTime = ((currentSong.duration) * percent) / 100
})

 // Add an event listener for hamburger
 document.querySelector(".hamburger").addEventListener("click", () => {
    document.querySelector(".left").style.left = "0"
})


 // Add an event listener for close button
 document.querySelector(".close").addEventListener("click", () => {
    document.querySelector(".left").style.left = "-120%"
})


//add an event listener to previous
previous.addEventListener("click", () => {
    console.log("previous clicked")
    console.log(currentSong)
})

//add an event listener to next 
next.addEventListener("click", () => {
    console.log("Next clicked")

    let index = songs.indexOf(currentSong.src.split("/").slice(-1) [0])
    if((index+1) > length )
    playMusic(songs[index+1])
})


main();
