const timer = document.querySelector(".lofidoro-timer");
const title = document.querySelector(".title");
const startBtn = document.querySelector(".startBtn");
const resetBtn = document.querySelector(".resetBtn");
const lofiCountsDisplay = document.querySelector(".lofiCountsDisplay");

let WORK_TIME = 25 * 60;
let timerID = null;
let isBreak = false;
let totalCount = 0;
let paused = false;
let running = false;

const updateTimer = () => {
  const selectedRadio = document.querySelector('input[name="timerType"]:checked');
  const timertext = selectedRadio ? `${selectedRadio.value}:00` : "25:00";
  timer.innerHTML = timertext;

  WORK_TIME = Number(selectedRadio.value) * 60;
  if (WORK_TIME < 1500) isBreak = true;
};

document.querySelectorAll('input[name="timerType"]').forEach((radio) => {
  radio.addEventListener("change", () => {
    (paused = false), (running = false);
    stopTimer();
    updateTimer();
    updateTitle("");
  });
});

const updateTitle = (msg) => {
  title.textContent = msg;
};

const updateButtonText = (text) => {
  startBtn.textContent = text;
};

const saveLocalCounts = () => {
  let counts = JSON.parse(localStorage.getItem("LofI-doroCounts")) || 0;
  counts++;
  localStorage.setItem("LofI-doroCounts", JSON.stringify(counts));
};

const countDown = (time) => {
  return () => {
    running = true;
    const mins = Math.floor(time / 60).toString().padStart(2, "0");
    const secs = Math.floor(time % 60).toString().padStart(2, "0");

    timer.textContent = `${mins}:${secs}`;
    time--;

    if (time < 0) {
      running = false;
      stopTimer();
      
      //Timer Sound
      const timerSound = document.getElementById("timerSound");
      timerSound.play();

      if (isBreak) {
        isBreak = false;
        updateTitle("Completed Break Time.");
      } else {
        updateTitle("Completed a focus session");
        setTimeout(() => updateTitle("Start Timer again for next session"), 2000);
        totalCount++;
        saveLocalCounts();
        showlofiCounts();
      }
    }
  };
};

const startTimer = (startTime) => {
  if (timerID !== null) {
    stopTimer();
  }

  return setInterval(countDown(startTime), 1000);
};

const stopTimer = () => {
  clearInterval(timerID);
  timerID = null;
};

const getTimeInSeconds = (timeString) => {
  const [minutes, seconds] = timeString.split(":");
  return parseInt(minutes * 60) + parseInt(seconds);
};

//
const showlofiCounts = () => {
  let counts = JSON.parse(localStorage.getItem("LofIdoroCounts"));
  
  if (counts > 0) {
    lofiCountsDisplay.style.display = "flex";
  }

  lofiCountsDisplay.firstElementChild.textContent = counts;
};


//Start-Pause Button 
startBtn.addEventListener("click", () => {
  if (!running) {
    timerID = startTimer(WORK_TIME);
    paused = false;
    updateButtonText("Pause");
    
    !isBreak
      ? updateTitle("Focus Mode Started")
      : updateTitle("Break Time Started");
  } else {
    if (!paused) {
      stopTimer();
      paused = true;
      updateButtonText("Start");
      updateTitle("Timer Paused");
    } else {
      const currentTime = getTimeInSeconds(timer.textContent);
      timerID = startTimer(currentTime);
      paused = false;
      updateButtonText("Pause");
      !isBreak ? updateTitle("It's Work Time") : updateTitle("It's LoFI-Time");
    }
  }
});

//Reset Button
resetBtn.addEventListener("click",function() {
  //Animations
  this.style.animation = 'none'; 
  this.offsetHeight; 
  this.style.animation = null; 
  this.classList.add('rotate');

  //Logic For Reset Button
  (paused = false), (running = false);
  updateButtonText("Start");
  stopTimer();
  updateTimer();
  updateTitle("");
});
