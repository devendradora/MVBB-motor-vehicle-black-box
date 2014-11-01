<?php

$page = $_SERVER['PHP_SELF'];
$sec = "0.5";
//echo '<meta http-equiv="refresh" content='.$secURL.'='.$page.'>';
error_reporting(E_ALL);
ini_set('display_errors', '1');
include "php_serial.class.php";


$serial = new phpSerial;
$serial->deviceSet('/dev/ttyUSB0');
$serial->confBaudRate(9600);
$serial->confParity("none");
$serial->confCharacterLength(8);
$serial->confStopBits(1);
$serial->deviceOpen();
$serial->sendMessage("Welcome");
$read = $serial->readPort();


print($read);

$serial->deviceClose();


?>
 <link class="include" rel="stylesheet" type="text/css" href="../jquery.jqplot.min.css" />
    <link rel="stylesheet" type="text/css" href="examples.min.css" />
    <link type="text/css" rel="stylesheet" href="syntaxhighlighter/styles/shCoreDefault.min.css" />
    <link type="text/css" rel="stylesheet" href="syntaxhighlighter/styles/shThemejqPlot.min.css" />
  
    <!--[if lt IE 9]><script language="javascript" type="text/javascript" src="../excanvas.js"></script><![endif]-->
    <script class="include" type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
    
<div id="chart1" style="width:500px; height:200px"></div>

    
   
 <script  type="text/javascript">

    $(document).ready(function () {
        var s1=[1,5,6,9,8,7,3,6,4,5,1];
       
        var s2 = [[2002, 10200], [2003, 10800], [2004, 11200], [2005, 11800], [2006, 12400], 
        [2007, 12800], [2008, 13200], [2009, 12600], [2010, 13100]];

        plot1 = $.jqplot("chart1", [s1], {
            // Turns on animatino for all series in this plot.
            animate: true,
            // Will animate plot on calls to plot1.replot({resetAxes:true})
            animateReplot: true,
            cursor: {
                show: true,
                zoom: true,
                looseZoom: true,
                showTooltip: false
            },
            series:[
                {
                    pointLabels: {
                        show: true
                    },
                   // renderer: $.jqplot.BarRenderer,
                    showHighlight: false,
                   // yaxis: 'y2axis',
                    rendererOptions: {
                        // Speed up the animation a little bit.
                        // This is a number of milliseconds.  
                        // Default for bar series is 3000.  
                        animation: {
                            speed: 2500
                        },
                        barWidth: 15,
                        barPadding: -15,
                        barMargin: 0,
                        highlightMouseOver: false
                    }
                }, 
                {
                    rendererOptions: {
                        // speed up the animation a little bit.
                        // This is a number of milliseconds.
                        // Default for a line series is 2500.
                        animation: {
                            speed: 2000
                        }
                    }
                }
            ],
            axesDefaults: {
                pad: 0
            },
            axes: {
                // These options will set up the x axis like a category axis.
                xaxis: {
                    tickInterval: 1,
                    drawMajorGridlines: false,
                    drawMinorGridlines: true,
                    drawMajorTickMarks: false,
                    rendererOptions: {
                    tickInset: 0.5,
                    minorTicks: 1
                }
                },
                // yaxis: {
                //     tickOptions: {
                //         formatString: "$%'d"
                //     },
                //     rendererOptions: {
                //         forceTickAt0: true
                //     }
                // },
                y2axis: {
                    tickOptions: {
                        formatString: "%'d"
                    },
                    rendererOptions: {
                        // align the ticks on the y2 axis with the y axis.
                        alignTicks: true,
                        forceTickAt0: true
                    }
                }
            },
            highlighter: {
                show: true, 
                showLabel: true, 
                tooltipAxes: 'y',
                sizeAdjust: 7.5 , tooltipLocation : 'ne'
            }
        });
      
    });


</script>
<!-- End example scripts -->

<!-- Don't touch this! -->


    <script class="include" type="text/javascript" src="../jquery.jqplot.min.js"></script>
    <script type="text/javascript" src="syntaxhighlighter/scripts/shCore.min.js"></script>
    <script type="text/javascript" src="syntaxhighlighter/scripts/shBrushJScript.min.js"></script>
    <script type="text/javascript" src="syntaxhighlighter/scripts/shBrushXml.min.js"></script>
<!-- Additional plugins go here -->

  <script class="include" type="text/javascript" src="../plugins/jqplot.barRenderer.min.js"></script>
  <script class="include" type="text/javascript" src="../plugins/jqplot.highlighter.min.js"></script>
  <script class="include" type="text/javascript" src="../plugins/jqplot.cursor.min.js"></script> 
  <script class="include" type="text/javascript" src="../plugins/jqplot.pointLabels.min.js"></script>

<!-- End additional plugins -->

       
    <script type="text/javascript" src="example.min.js"></script>
