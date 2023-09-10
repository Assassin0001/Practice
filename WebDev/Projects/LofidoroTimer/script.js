const timer = document.querySelector('.timer');
const title = document.querySelector('.title');
const startBtn = document.querySelector('.startBtn');
const pauseBtn = document.querySelector('.pauseBtn');
const resumeBtn = document.querySelector('.resumeBtn');
const resetBtn = document.querySelector('.resetBtn');
const pomoCountsDisplay = document.querySelector('.lofiCountsDisplay');

//making variables
const WORK_TIME = 25 * 60;
const BREAK_TIME = 5 * 60;
let timerID = null;
let breakDone = false;
let totalCount = 0;
let paused = false;

//Title Updation Function
const updateTitle = (msg) => {
  title.textContent = msg;
}

//Function to save pomoCount to localStorage
const saveLocalCounts = () => {
  let counts = JSON.parse(localStorage.getItem("LofI-doroCounts"));
  counts !== null ? counts++ : counts = 1;
  localStorage.setItem("LofI-doroCounts", JSON.stringify(counts));

}
//CountDown function
const countDown = (time) => {
  return () => {
    const mins = Math.floor(time / 60).toString().padStart(2, '0');
    const secs = Math.floor(time % 60).toString().padStart(2, '0');

    timer.textContent = `${mins}:${secs}`;
    time--;
    if (time < 0) {
      stopTimer();
      if (!breakDone) {
        timerID = startTimer(BREAK_TIME);
        breakDone = true;
        updateTitle("It's LofI-Time");
      }
      else {
        updateTitle('Completed a focus session');
        setTimeout(() => updateTitle('Start Timer again for next session'), 2000);
        totalCount++;
        saveLocalCounts();
        showPomoCounts();
      }
    }
  }
}

//Arrow function for startTimer Button
const startTimer = (startTime) => {
  if (timerID !== null) { stopTimer(); }
  return setInterval(countDown(startTime), 1000);
}

//Arrow function for stopTimer Button 
const stopTimer = () => {
  clearInterval(timerID);
  timerID = null;
}

//Arrow function to get Time in seconds 
const getTimeInSeconds = (timeString) => {
  const [minutes, seconds] = timeString.split(":");
  return parseInt(minutes * 60) + parseInt(seconds);
}

//Arrow function to show Completed PomoCounts
const showPomoCounts = () => {
  let counts = JSON.parse(localStorage.getItem("LofIdoroCounts"));
  if (counts > 0) {
    pomoCountsDisplay.style.display = "flex";
  }
  pomoCountsDisplay.firstElementChild.textContent = counts;
}

//Adding eventListener to startButton
startBtn.addEventListener('click', () => {
  timerID = startTimer(WORK_TIME);
  updateTitle('Focus Mode Started');
});

//Adding eventListener to resetButton
resetBtn.addEventListener('click', () => {
  stopTimer();
  timer.textContent = "25:00";
});

//Adding eventListener to pauseButton
pauseBtn.addEventListener('click', () => {
  stopTimer();
  paused = true;
  updateTitle("Timer Paused");
});

//Adding eventListener to resumeButton
resumeBtn.addEventListener('click', () => {
  if (paused) {
    const currentTime = getTimeInSeconds(timer.textContent);
    timerID = startTimer(currentTime);
    paused = false;
    (!breakDone) ? updateTitle("It's Work Time") : updateTitle("It's LofI-Time");
  }
});