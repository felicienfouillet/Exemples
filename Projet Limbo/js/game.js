var game = new Phaser.Game(1250,650,Phaser.CANVAS,'gameDiv',{preload: preload, create: 
create,update:update,render:render});

var map;
var groundLayer;

var player;
var box;
var music;

var platforms;
var boxes;
var sink;
var sink_1;

var facing;

var cursors;
var jumpButton;
var interaction;

var timeLabel;
var startTime;
var totalTime;
var timeElapsed;
var result;
var minTimeScore;
var secTimeScore;

var jumpTimer = 0;


function preload(){
    /*      Music       */

    game.load.audio('gameMusic', 'asset/musics/Path to Lake Land.ogg');

    /*      Sprites      */

	game.load.spritesheet('esther', 'asset/player.png', 90, 90);   //Player
    game.load.spritesheet('sink', 'asset/levier.png', 183, 194);    //Sink

    /*      Background      */

    game.load.image('background_1', 'asset/font.jpg');   //Font 1
    game.load.image('background_2', 'asset/font2.jpg');  //Font 2
    game.load.image('background_3', 'asset/font3.jpg');  //Font 3
    game.load.image('background_4', 'asset/font4.jpg');  //Font 4

    /*      Tilemap      */
    
    game.load.tilemap('tilemap', 'asset/tilemaps/tilemap.json', null, Phaser.Tilemap.TILED_JSON);    //Tilemap
    game.load.image('tiles', 'asset/tilemaps/arcade-slopes-16.png');  //Tileset

    /*      Objects      */
    
    game.load.image('plateform_1', 'asset/plateform_1.png');    //Plateform 1
    game.load.image('plateform_2', 'asset/plateform_2.png');    //Plateform 2
    game.load.image('plateform_3', 'asset/plateform_3.png');    //Plateform 3
    game.load.image('plateform_4', 'asset/plateform_4.png');    //Plateform 4

    game.load.image('box', 'asset/box.png');  //Box
}

function create(){
    /*      Plugins      */

    game.plugins.add(Phaser.Plugin.ArcadeSlopes);

    game.physics.startSystem(Phaser.Physics.ARCADE);    //Start Arcade Physics

    game.world.resize(31440, 650);  //Dimention du jeux;

    /*      Music       */

    music = game.add.audio('gameMusic');
    music.play();
    music.loopFull(1);

    /*      Tilemaps      */

    CreateTilemap();

    /*      Fonts     */

    game.add.sprite(0, 0, 'background_1');
    game.add.sprite(10000, 0, 'background_2');
    game.add.sprite(20000, 0, 'background_3');
    game.add.sprite(30000, 0, 'background_4');


    /*      Groups     */

    platforms = game.add.group();
    platforms.enableBody = true;

    boxes = game.add.group();
    boxes.enableBody = true;

    /*      Plateforms     */

    CreatePlateforms(13673, 552, 'plateform_1', 0.01, 0.3);
    CreatePlateforms(13580, 492, 'plateform_1', 0.01, 0.3);

    CreatePlateforms(15172, 255, 'plateform_1', 0.4, 0.3);

    Player();

    Sink();

    /*          Objects         */

    /*      Boxs     */

    CreateBoxes(23500, 350, 'box', 0.3, 0.3);

    /*      Buttons     */

    cursors = game.input.keyboard.createCursorKeys();
    jumpButton = game.input.keyboard.addKey(Phaser.Keyboard.SPACEBAR);
    interaction = game.input.keyboard.addKey(Phaser.Keyboard.A);

    game.add.text(50, 25, "Press A to interact (with sink/box/...)", {font: "15px Arial", fill: "#fff"});

    /*      Game timer     */

    startTime = new Date();
    totalTime = 0;
    timeElapsed = 0;
 
    CreateTimer();
}

function update(){
    UpdateTimer();

    /*      Collisions     */

    game.physics.arcade.collide(player, groundLayer);
    game.physics.arcade.collide(player, platforms);
    game.physics.arcade.collide(player, boxes);

    game.physics.arcade.collide(boxes, groundLayer);
    game.physics.arcade.collide(boxes, platforms);

    /*      Movement     */

    player.body.velocity.x = 0;

    if(cursors.left.isDown){
        player.body.velocity.x = -150;

        if (facing != 'left')
        {
            player.animations.play('left');
            facing = 'left';
        }
    }else if (cursors.right.isDown){
        player.body.velocity.x = 150;

        if (facing != 'right')
        {
            player.animations.play('right');
            facing = 'right';
        }
    }else{
        if (facing != 'idle')
        {
            player.animations.stop();

            if (facing == 'left')
            {
                player.frame = 10;
            }
            else
            {
                player.frame = 3;
            }

            facing = 'midle';
        }
    }

    if(jumpButton.isDown && game.time.now > jumpTimer){
        player.body.velocity.y = -450;
        jumpTimer = game.time.now + 1000;
    }

    /*******************************/
    /*   Enigmes des Plateformes   */
    /*******************************/

    //Première partie d'eau
    if(player.body.x >= 15165 && player.body.x <= 15220 && player.body.y >= 160 && player.body.y <= 170 && interaction.isDown){
        sink.frame = 1;

        CreatePlateforms(15320, 410, 'plateform_1', 1, 0.3);
        CreatePlateforms(15720, 470, 'plateform_2', 0.5, 0.3);
        CreatePlateforms(15950, 440, 'plateform_4', 0.75, 0.3);
        CreatePlateforms(16090, 540, 'plateform_3', 0.7, 0.3);
        CreatePlateforms(16000, 300, 'plateform_1', 0.4, 0.3);
        CreatePlateforms(16000, 200, 'plateform_2', 0.2, 0.3);
        CreatePlateforms(16215, 175, 'plateform_1', 0.4, 0.3);
    }

    //Seconde partie d'eau
    if(player.body.x >= 16340 && player.body.x <= 16440 && player.body.y >= 450 && interaction.isDown){
        sink_1.frame = 1;

        CreatePlateforms(17735, 605, 'plateform_4', 0.4, 0.3);
        CreatePlateforms(17925, 580, 'plateform_4', 1, 0.3);
        CreatePlateforms(18125, 580, 'plateform_1', 1, 0.3);
        CreatePlateforms(18530, 550, 'plateform_2', 1, 0.3);
        CreatePlateforms(18950, 585, 'plateform_3', 1, 0.3);
    }

    MoveBox();

    Death();

    GetWin();
}

function CreateTilemap(){
    /* Tilemap */

    map = game.add.tilemap('tilemap');                      //Création de la map
    map.addTilesetImage('arcade-slopes-16', 'tiles');

    /* Layers */

    groundLayer = map.createLayer('GroundLayer');           //Création du Layer
    map.setCollisionBetween(1, 25, true, 'GroundLayer');

    /*  Arcade Slopes  */
    game.slopes.convertTilemapLayer(groundLayer, {  //Appel du plugin Arcade Slopes
        1: 'FULL',                                  //et convertion des tiles.
        2: 'HALF_TOP',
        3: 'HALF_BOTTOM',
        4: 'HALF_LEFT',
        5: 'HALF_RIGHT',
        6: 'HALF_BOTTOM_LEFT',
        7: 'HALF_BOTTOM_RIGHT',
        8: 'HALF_TOP_LEFT',
        9: 'HALF_TOP_RIGHT',
        10: 'QUARTER_TOP_LEFT_HIGH',
        11: 'QUARTER_TOP_LEFT_LOW',
        12: 'QUARTER_TOP_RIGHT_LOW',
        13: 'QUARTER_TOP_RIGHT_HIGH',
        14: 'QUARTER_BOTTOM_LEFT_HIGH',
        15: 'QUARTER_BOTTOM_LEFT_LOW',
        16: 'QUARTER_BOTTOM_RIGHT_LOW',
        17: 'QUARTER_BOTTOM_RIGHT_HIGH',
        18: 'QUARTER_LEFT_BOTTOM_HIGH',
        19: 'QUARTER_RIGHT_BOTTOM_HIGH',
        20: 'QUARTER_LEFT_TOP_HIGH',
        21: 'QUARTER_RIGHT_TOP_HIGH',
        22: 'QUARTER_LEFT_BOTTOM_LOW',
        23: 'QUARTER_RIGHT_BOTTOM_LOW',
        24: 'QUARTER_LEFT_TOP_LOW',
        25: 'QUARTER_RIGHT_TOP_LOW'
    });
}

function Player(){
    player = game.add.sprite(15000, 40, 'esther'); //Sprite Display
    
    player.animations.add('right', [4, 5, 6, 11, 12, 13], 8, true);         //Right player animation
    player.animations.add('left', [9, 8, 7, 2, 1, 0], 8, true);    //Left player animation

    game.physics.arcade.enable(player); //Setting up player physics
    game.slopes.enable(player);

    player.body.bounce.y = 0.05;                 //Player little rebounds
    player.body.gravity.y = 1000;               //Player gravity
    player.body.collideWorldBounds = true;      //Bordure collisions

    game.camera.follow(player, Phaser.Camera.FOLLOW_LOCKON, 0.2, 0.2);  //Camera effect
}

function Sink(){
    sink = game.add.sprite(15115, 170, 'sink');
    sink_1 = game.add.sprite(16475, 490, 'sink');

    sink.scale.setTo(0.35, 0.35);
    sink_1.scale.setTo(0.35, 0.35);

    sink.frame = 0;
    sink_1.frame = 0;
}

function CreatePlateforms(x, y, spriteName, scaleX, scaleY){
    //Ajout des plateformes au groupe
    var ledge = platforms.create(x, y, spriteName);
    ledge.body.immovable = true; //Collision

    ledge.scale.setTo(scaleX, scaleY);  //Taille d'affichage
}

function CreateBoxes(x, y, spriteName, scaleX, scaleY){
    //Ajout des boites au groupe
    box = boxes.create(x, y, spriteName);
    box.body.immovable = true;  //Fixation au fond
    box.scale.setTo(scaleX, scaleY);    //Taille

    game.physics.arcade.enable(box);    //Ajout de la physique et du plugin
    game.slopes.enable(box);

    box.body.bounce.y = 0.1;               //Propriétés des boites
    box.body.gravity.y = 1000;
    box.body.collideWorldBounds = true;
}

function MoveBox(){
    if(interaction.isDown){
        box.body.immovable = false; //Annulation de la fixation
    }else{
        box.body.immovable = true;  //Blocage des boites
        box.body.velocity.x = 0;
    }
}

function Death(){
    //Récupération de la position du joueur    
    if(player.body.x >= 15456 && player.body.x <= 16134 && player.body.y >= 552){
        player.body.x = 150;        //Retour au début s'il est mort
        player.body.y = 350;
        alert('Vous êtes mort..');
    }else if(player.body.x >= 17736 && player.body.x <= 19144 && player.body.y >= 560){
        player.body.x = 150;
        player.body.y = 350;
        alert('Vous êtes mort..');
    }
}

function GetWin(){ //Vérification de la victoire
    if(player.body.x >= 31300){
        window.location.href="end_game.html";
        sessionStorage.setItem('minTimeScore', minTimeScore);   //Récuperation du temps
        sessionStorage.setItem('secTimeScore', secTimeScore);
    }
}

function CreateTimer(){     //Affichage du Timer
    timeLabel = game.add.text(625, 50, "00:00", {font: "50px Arial", fill: "#fff"});
    timeLabel.anchor.setTo(0.5, 0.5);
    timeLabel.align = 'center';
    timeLabel.fixedToCamera = true;
}

function UpdateTimer(){     //Fonctionnement du Timer
    var currentTime = new Date();
    var timeDifference = startTime.getTime() - currentTime.getTime();
 
    //Temps écoulé en secondes
    timeElapsed = Math.abs(timeDifference / 1000);
 
    //Temps total en secondes
    var timer = totalTime + timeElapsed;

    //Convertion des secondes en minutes et secondes 
    var minutes = Math.floor(timer / 60);
    var seconds = Math.floor(timer) - (60 * minutes);
 
    //Affichage des minutes
    result = (minutes < 10) ? "0" + minutes : minutes;
 
    //Affichage des secondes
    result += (seconds < 10) ? ":0" + seconds : ":" + seconds;

    minTimeScore = (minutes < 10) ? "0" + minutes : minutes;
    secTimeScore = (seconds < 10) ? "0" + seconds : + seconds;

    timeLabel.text = result;
}

function render(){  //Pour le développement
    /*game.debug.cameraInfo(game.camera, 32, 32);
    game.debug.spriteCoords(player, 32, 500);
    game.debug.inputInfo(32, 250);*/
}