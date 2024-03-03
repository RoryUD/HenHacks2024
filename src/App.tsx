import React, { useState } from "react";
import "./App.css";
import { Button, Col, Container, Row } from "react-bootstrap";
function App(): JSX.Element {
    const [widgets, setWidgets] = useState<string[]>([]);
    const [widgets2, setWidgets2] = useState<string[]>([]);
    const [widgets3, setWidgets3] = useState<string[]>([]);
    const [widgets4, setWidgets4] = useState<string[]>([]);

    function handleOnDrag(e: React.DragEvent, widgetType: string){
        e.dataTransfer.setData("widgetType", widgetType);
    }

    function handleOnDrop(e:React.DragEvent){
        const widgetType = e.dataTransfer.getData("widgetType") as string;
        console.log("widgetType", widgetType);
        setWidgets([...widgets, widgetType]);
    }

    function handleDragOver(e: React.DragEvent){
        e.preventDefault();
    }

    function removeAllWidgets() {
        setWidgets([]);
    }

    function removeAllWidgets2() {
        setWidgets2([]);
    }

    function removeAllWidgets3() {
        setWidgets3([]);
    }

    function removeAllWidgets4() {
        setWidgets4([]);
    }

    function handleOnDrop2(e:React.DragEvent){
        const widgetType = e.dataTransfer.getData("widgetType") as string;
        console.log("widgetType", widgetType);
            setWidgets2([...widgets2, widgetType]);
    }

    function handleOnDrop3(e:React.DragEvent){
        const widgetType = e.dataTransfer.getData("widgetType") as string;
        console.log("widgetType", widgetType);
            setWidgets3([...widgets2, widgetType]);
    }

    function handleOnDrop4(e:React.DragEvent){
        const widgetType = e.dataTransfer.getData("widgetType") as string;
        console.log("widgetType", widgetType);
            setWidgets4([...widgets2, widgetType]);
    }



    return (
        <div className="App">
            <h1>Gender Inclusive Language Examples</h1>
            <header className="App-header">
            <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/48/Gay_Pride_Flag.svg/800px-Gay_Pride_Flag.svg.png" style={{width: 1600, height: 200}} alt="Pride Flag"></img>
            </header>
            <p >
                This site is designed to teach you about gendered langauge!
				<div>
				You can move parts of sentences around to rewrite a give sentence to not include gendered language.
				</div>
				<div>
				This first sentence is about removing gendered pronouns without having to rewrite the sentence fully.
				</div>
				<div>
				Here is the first sentence: A good computer scientist does his or her job efficently
				</div>
            </p>
            <div className="widgets">
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, " A good computer scientist ")}
                >
                    A good computer scientist
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, " does his or her ")}
                >
                    does his or her
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, " does their ")}
                >
                    does their
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, " does the ")}
                >
                    does the
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, " job efficently ")}
                >
                    job efficently
                </div>
            </div>
            <div className="page" onDrop={handleOnDrop} onDragOver={handleDragOver}>
                Drop Here: 
                {widgets.map((widget, index) => (
                    <div className="dropped-widget" key={index}>
                        {widget}
                    </div>
                ))}
                <div className="button-container">
                    <Button onClick={removeAllWidgets}>
                        Reset
                    </Button>
                </div>
            </div>
            
            <p>
                As you can see, you can remove gendered language in various ways.
				<div>
				This next example is when a singular person is talking about multiple people.
				</div>
				<div>
				In this case, it is best to use they/them/their to refer to just a single group.
				</div>
				<div>
				Here is the second sentence: A pet owner should treat his or her pets well.
				</div>
            </p>
            
            <div className="widgets2">
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "A pet owner")}
                >
                    A pet owner
                </div>
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Pet owners")}
                >
                    Pet owners
                </div>
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "should treat")}
                >
                    should treat
                </div>
				<div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "their pets")}
                >
                    their pets
                </div>
				<div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "his or her pets")}
                >
                    his or her pets
                </div>
				<div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "well")}
                >
                    well
                </div>
            </div>
            <div className="page" onDrop={handleOnDrop2} onDragOver={handleDragOver}>
                Drop Here: 
                {widgets2.map((widget2, index) => (
                    <div className="dropped-widget" key={index}>
                        {widget2}
                    </div>
                ))}
                <div className="button-container">
                    <Button onClick={removeAllWidgets2}>
                        Reset
                    </Button>
                </div>
            </div>
            
            <p>
                Many words can be gendered in subtler ways, but can still be avoided.
				<div>
				For example, instead of "mankind" you can use "humankind".
				</div>
				<div>
				Here is the third sentence: Anyone can write to his or her Congressman about important issues.
				</div>
            </p>
            <div className="widgets3">
                <div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Anyone can write")}
                >
                    Anyone can write
                </div>
                <div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "to his or her")}
                >
                    to his or her
                </div>
                <div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "to their")}
                >
                    to their
                </div>
				<div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Congressman")}
                >
                    Congressman
                </div>
				<div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Representative")}
                >
                    Representative
                </div>
				<div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "about important issues")}
                >
                    about important issues
                </div>
            </div>
            <div className="page" onDrop={handleOnDrop3} onDragOver={handleDragOver}>
                Drop Here: 
                {widgets3.map((widget3, index) => (
                    <div className="dropped-widget" key={index}>
                        {widget3}
                    </div>
                ))}
                <div className="button-container">
                    <Button onClick={removeAllWidgets3}>
                        Reset
                    </Button>
                </div>
            </div>

            <p>
                Placeholder shmext
            </p>

            <div className="widgets4">
                <div
                    className="widget4"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget D")}
                >
                    Widget D
                </div>
                <div
                    className="widget4"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget E")}
                >
                    Widget E
                </div>
                <div
                    className="widget4"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget F")}
                >
                    Widget F
                </div>
            </div>
            <div className="page" onDrop={handleOnDrop4} onDragOver={handleDragOver}>
                Drop Here: 
                {widgets4.map((widget4, index) => (
                    <div className="dropped-widget" key={index}>
                        {widget4}
                    </div>
                ))}
                <div className="button-container">
                    <Button onClick={removeAllWidgets4}>
                        Reset
                    </Button>
                </div>
            </div>
            <p style={{padding: 25}}>
                Placeholder paragaph
            </p>
        </div>
    );
}
export default App;
