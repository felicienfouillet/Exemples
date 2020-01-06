var minTimeScore_top1 = sessionStorage.getItem("minTimeScoreTop1");
var minTimeScore_top2 = sessionStorage.getItem("minTimeScoreTop2");
var minTimeScore_top3 = sessionStorage.getItem("minTimeScoreTop3");

var secTimeScore_top1 = sessionStorage.getItem("secTimeScoreTop1");
var secTimeScore_top2 = sessionStorage.getItem("secTimeScoreTop2");
var secTimeScore_top3 = sessionStorage.getItem("secTimeScoreTop3");

var minTimeScore = sessionStorage.getItem("minTimeScore");
var secTimeScore = sessionStorage.getItem("secTimeScore");

var top1 = minTimeScore_top1 + ":" + secTimeScore_top1;
var top2 = minTimeScore_top2 + ":" + secTimeScore_top2;
var top3 = minTimeScore_top3 + ":" + secTimeScore_top3;

var score = minTimeScore + ":" + secTimeScore;

var sound;

function preload(){
	sound = loadSound('asset/musics/Harp.ogg');	//Chargement du son
}

function setup(){
	playSound();
}

function playSound(){	//Fonction liée au son dans les menus
  	sound.play();
  	sound.loop();
}

function createSessionStorage(){

	//Création de toutes les variables utiles
	if(typeof(Storage) !== "undefined"){
		if (sessionStorage.getItem("stateSessionStorage") == null){
			sessionStorage.setItem("minTimeScore",0);
			sessionStorage.setItem("secTimeScore",0);

			sessionStorage.setItem("top1",0);
			sessionStorage.setItem("top2",0);
			sessionStorage.setItem("top3",0);

			sessionStorage.setItem("minTimeScoreTop1",100);
			sessionStorage.setItem("minTimeScoreTop2",100);
			sessionStorage.setItem("minTimeScoreTop3",100);

			sessionStorage.setItem("secTimeScoreTop1",100);
			sessionStorage.setItem("secTimeScoreTop2",100);
			sessionStorage.setItem("secTimeScoreTop3",100);

			sessionStorage.setItem("stateSessionStorage", 1);
		}
	} else{
		alert("Désolé, votre navigateur ne supporte pas le web Storage...");
	}
}

function showScore(){

	//Classement des Score
	if(typeof(Storage) !== "undefined"){
		if(minTimeScore <= minTimeScore_top1){	//Vérification des minutes
			if(secTimeScore <= secTimeScore_top1){	//Vérification des secondes
				sessionStorage.setItem("minTimeScoreTop3", minTimeScore_top2);
				sessionStorage.setItem("secTimeScoreTop3", secTimeScore_top2);
				sessionStorage.setItem("minTimeScoreTop2", minTimeScore_top1);
				sessionStorage.setItem("secTimeScoreTop2", secTimeScore_top1);
				sessionStorage.setItem("minTimeScoreTop1", minTimeScore);
				sessionStorage.setItem("secTimeScoreTop1", secTimeScore);
			}
		}else if(minTimeScore <= minTimeScore_top2){
			if(secTimeScore <= secTimeScore_top2){
				sessionStorage.setItem("minTimeScoreTop3", minTimeScore_top2);
				sessionStorage.setItem("secTimeScoreTop3", secTimeScore_top2);
				sessionStorage.setItem("minTimeScoreTop2", minTimeScore);
				sessionStorage.setItem("secTimeScoreTop2", secTimeScore);
			}
		}else if(minTimeScore <= minTimeScore_top3){
			if(secTimeScore <= secTimeScore_top3){
				sessionStorage.setItem("minTimeScoreTop3", minTimeScore);
				sessionStorage.setItem("secTimeScoreTop3", secTimeScore);
			}
		}

		document.getElementById('score').innerHTML = "score: " + score;

		document.getElementById('top1').innerHTML = "1: " + top1;
		document.getElementById('top2').innerHTML = "2: " + top2;
		document.getElementById('top3').innerHTML = "3: " + top3;
	} else{
		alert("Désolé, votre navigateur ne supporte pas le web Storage...");
	}
}