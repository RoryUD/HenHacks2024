import React, { useState } from "react";
import "./App.css";
import { Button, Col, Container, Row } from "react-bootstrap";
function App(): JSX.Element {
    const [widgets, setWidgets] = useState<string[]>([]);

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
            </div>
            
            <Button onClick={() => console.log("Hello World!")}>
                Log Hello World
            </Button>
        </div>
    );
}
export default App;