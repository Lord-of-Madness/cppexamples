﻿using Godot;
using RTS.Graphics;

//using MonoCustomResourceRegistry;
using RTS.Physics;
using System.Linq;
namespace RTS.Gameplay
{
    [GlobalClass]
    public partial class BuildBuildingAbility : TargetedAbility
    {
        private string text = "Build _missing_";
        public override string Text { get => text; set => text = value; }

        public override Second Cooldown => new(0f);

        public override bool Active => true;

        bool OnTheWayToBuild = false;

        bool ptl;
        bool PickingTargetLocation
        {
            get => ptl; set
            {
                ptl = value;
                wireframe.Visible = value;
            }
        }

        public Building building;

        public Sprite2D wireframe;
        public BuildBuildingAbility(Building building)
        {
            this.building = building;
            Text = "Build " + building.Name;
        }
        public override void OnClick(AbilityButton button)
        {
            base.OnClick(button);
            PickingTargetLocation = true;

            GD.Print("TODO: Display building wireframe at the mouseposition");
        }
        Vector2 targetLocation;

        bool BuildingFits(Vector2 location)
        {
            PhysicsShapeQueryParameters2D query = new()
            {
                Shape = building.BuildingCollision,
                Transform = new Transform2D(0, location)
            };


            GodotObject[] collisions = (from s in OwningSelectable.OwnerPlayer.localLevel.GetWorld2D().DirectSpaceState.IntersectShape(query, 780)
                                        where (GodotObject)s["collider"] != OwningSelectable
                                        select (GodotObject)s["collider"]).ToArray();
            /*var area = new Area2D();
            area.AddChild(new CollisionShape2D() { Shape = building.BuildingCollision });
            area.Position = location;*/
            if (collisions.Length == 0) return true;
            return false;
            //TODO Building fits?
            //Put an Area2D on the location. if it doesn't collide with anything but non-coliding ground return true otherwise false
        }

        public override void OnTargetRecieved(Target target)
        {
            //base.OnTargetRecieved(target);The base one a) checks if its already in Range, b) starts monitoring. And we don't need either cause we run it in process
            PickingTargetLocation = false;
            if (target.type == Target.Type.Location
                && BuildingFits(target.location)
                ) { targetLocation = target.location; OnTheWayToBuild = true; }

        }

        public override void OnTargetReached()
        {
            if (!BuildingFits(targetLocation)) GD.Print("Cannot build there");
            else
            {
                //TODO: Make sure the building gets placed properly && there is nothing in the way + wait if there is anything in the way + give friendlies command to move outoff the way etc. etc.
                Building newBuilding = (Building)building.Duplicate();
                newBuilding.Position = targetLocation;
                OwningSelectable.AddSibling(newBuilding);
                OnTheWayToBuild = false;
            }
        }

        protected override bool IsTarget(Node2D shape)
        {
            return false;//we are not looking for a body
        }
        public override void _Process(double delta)
        {
            base._Process(delta);
            if (OwningSelectable.OwnerPlayer is HumanPlayer && PickingTargetLocation)//this is an UI thing. Is it wise to put it with the rest of the gameplay code?
            {
                wireframe.Position = GetViewport().GetMousePosition();
                if (BuildingFits(wireframe.Position))
                {
                    wireframe.Modulate = new(1, 1, 1);
                }
                else wireframe.Modulate = new(1, 0.1f, 0.1f);
            }
            if (OnTheWayToBuild && OwningSelectable.Position.DistanceTo(targetLocation) <= Range) { OnTargetReached(); }
        }
        public override void _Ready()
        {
            base._Ready();
            wireframe = (Sprite2D)building.GetNode<SelectableGraphics>("Graphics").GetNode<Sprite2D>(nameof(Sprite2D)).Duplicate();
            wireframe.Modulate = new(1, 1, 1, 0.3f);
            AddChild(wireframe);
            PickingTargetLocation = false;
        }
    }
}