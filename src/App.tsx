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
                Interactive Examples to enhance language for diversity:
            </header>
            <p>
                Placeholder Paragraph
            </p>
            <div className="widgets">
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget A")}
                >
                    Widget A
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget B")}
                >
                    Widget B
                </div>
                <div
                    className="widget"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget C")}
                >
                    Widget C
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
                        Remove All Widgets
                    </Button>
                </div>
            </div>
            
            <p>
                Placeholder Paragraph
            </p>
            
            <div className="widgets2">
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget D")}
                >
                    Widget D
                </div>
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget E")}
                >
                    Widget E
                </div>
                <div
                    className="widget2"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget F")}
                >
                    Widget F
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
                        Remove All Widgets
                    </Button>
                </div>
            </div>
            
            <p>
                Placeholder 
            </p>
            <div className="widgets3">
                <div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget D")}
                >
                    Widget D
                </div>
                <div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget E")}
                >
                    Widget E
                </div>
                <div
                    className="widget3"
                    draggable
                    onDragStart={(e) => handleOnDrag(e, "Widget F")}
                >
                    Widget F
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
                        Remove All Widgets
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
                        Remove All Widgets
                    </Button>
                </div>
            </div>

        </div>
    );
}
export default App;
